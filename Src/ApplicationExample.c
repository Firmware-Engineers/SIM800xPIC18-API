//-----------------------------------
#include "../Inc/ApplicationExample.h"
#include "../../../../M8M_APIs/PIC18.X/Inc/SoftwareUART.h"
//-----------------------------------

//-----------------------------------
/*
    {
       "Engine Temperature (C)":30,
       "RPM":3500,
       "Vehicle Speed (MPH)":35,
       "Fuel Level (%)":50
    }
*/
char txmessage[100];
//-----------------------------------

/*
    {
       "Success Code": 200
    }
*/
char rxmessage[30];
//-----------------------------------

uint16_t cpos = 0;
//-----------------------------------

//-----------------------------------
#define mkstr(x)                   #x
#define URL                         "http://backend.thinger.io/v3/users/FirmwareEngineers/devices/SIM800L/callback/data?authorization=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJleHAiOjE2ODAzNjA0NzAsImlhdCI6MTY4MDM1MzI3MCwicm9sZSI6InVzZXIiLCJ1c3IiOiJGaXJtd2FyZUVuZ2luZWVycyJ9.5MYrPVS4nFa2kou3dV2yZP4Svo3JV1Zj6gAIGTVui94"
//-----------------------------------

uint8_t SystemInit(void)
{
    SystimeInit();                                                              //!< Initialize the System Time API
    USARTAsyncInit(103);                                                        //!< Initialize the USART/UART library, br = 9600
    SoftUARTInit();                                                             //!< Initialize Software UART driver
    //---------    
    if(SIM800xInit() == SIM800X_OK)
    {
        SoftUARTPrint("Modem Initialized.\r\r");
        //
        // Set IP configuration
        //
        SoftUARTPrint("Setting IP configurations...\r");
        if(SIM800xIPSetConnectionType(1, "GPRS") == SIM800X_OK)                 //!< Set bearer connection type
        {
            if(SIM800xIPSetAPN(1, "Internet") == SIM800X_OK)                    //!< Set APN = "Internet" for MTN Cameroon.                                 
            {
                if(SIM800xIPOpen(1) == SIM800X_OK)                              //!< Activate bearer profile [cid = 1, Contype = "GPRS", APN = Internet]
                {
                    char ip[20];
                    SoftUARTPrint("Done.\r\r");                    
                    SIM800xIPGetState(1, ip);                                   //!< Get IP address
                    SoftUARTPrint("Bearer profile Activated, IP: ");
                    SoftUARTPrint(ip);
                    SoftUARTPrint("\r\r");
                    uint16_t err;
        //
        // Set HTTP settings
        //
                    SoftUARTPrint("Setting HTTP configurations...\r");
                    if(SIM800xHTTPInit(&err) == SIM800X_OK)                     //!< Initialize HTTP service
                    {
                        if(SIM800xHTTPSetURL(URL, &err) == SIM800X_OK)          //!< Set HTTP server URL (Obtained on thinger.io, device name is SIM800L)
                        { 
                            if(SIM800xHTTPSetContent("application/json", &err) == SIM800X_OK)       //!< Set HTTP Conten-Type parameter to "application/json"
                            {
                                SoftUARTPrint("Done.\r\r");
        //
        // Serialize message to be sent into JSON format
        //
                                //---------                                                                          
                                AddEntryToJsonObject(txmessage, "Engine Temperature (C)", mkstr(30), &cpos);
                                AddEntryToJsonObject(txmessage, "RPM", mkstr(3500), &cpos);
                                AddEntryToJsonObject(txmessage, "Vehicle Speed (MPH)", mkstr(35), &cpos);
                                AddEntryToJsonObject(txmessage, "Fuel Level (%)", mkstr(50), &cpos);
                                //---------
        //
        // Serialize message to be sent into JSON format
        //
                                SoftUARTPrint("System Initialization completed.\r\r");
                                return SIM800X_OK;
                            }   
                        }                          
                    }
                }
            }
        }   
    }
    SoftUARTPrint("System Initialization failed.\r\r");
    return 1;
    //---------
}
//-----------------------------------

void SystemTask(void)
{
    uint8_t cmd = 0;
    uint16_t scode = 0, errcode = 0;
    uint32_t cnt = 0;
    if(SoftUARTRxAvailable())
        cmd = (uint8_t)SoftUARTReceiveByte();
    if(cmd == '1')
    {
        //---------
        SoftUARTPrint("Sending message to thinger.io...\r");
        //---------
        SIM800xHTTPInputData(txmessage, (uint32_t)(cpos + 1), 5000, &errcode);  //!< Send data to modem buffer
        //---------
        if(SIM800xHTTPAction(1, &scode, &cnt, 10000, &errcode) == SIM800X_OK)   //!< Send a POST request to the server and wait response for 10s max.
        {
            if(SIM800xHTTPRead(rxmessage, 0, cnt, &cnt, &errcode) == SIM800X_OK)        //!< Read HTTP response from the server.
            {
                char msg[20];
                sprintf(msg, "HTTP response code: %u\r", scode);
                SoftUARTPrint(msg);
                sprintf(msg, "Received data length: %ld\r", cnt);
                SoftUARTPrint(msg);
                SoftUARTPrint("Data: ");
                SoftUARTPrint(msg);
                SoftUARTPrint("\r\r");
            }
        }else
        {
            SoftUARTPrint("Sending failed.\r");
        }
        //---------
        cmd = 0;
    }
    
}
//-----------------------------------