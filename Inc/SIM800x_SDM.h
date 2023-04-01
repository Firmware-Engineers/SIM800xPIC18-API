/**
 ******************************************************************************
 * @file            SIM800x_SDM.h
 * @author          Maxime  
 * @brief           Header file for SIM800 series Modem API Serial Data Manager (SDM)
 * @brief           This file provides macros and function definitions used to handle
 *                  serial data received by the Modem (DCE/TA), from the Controlling 
 *                  device (DTE/TE).
 * 
 * @note            **This driver is at the heart of the WWAN APIs operation, and is 
 *                  responsible for receiving and performing every parsing,  
 *                  and extracting operations on the data receive from the serial interface, 
 *                  so that the later can be used effectively by the API functions.**
 * 
 * @warning         This driver uses the target controller: 
 *                      - UART/USART module
 *                      - UART/USART instance 1 on STM32 
 *                      - Interrupt on receive functionality
 *                  **Two functions, SIM800xSDMResume and SIM800xSDMSuspend, are implemented 
                    for enabling/disabling this driver.** 
 *                  
 * @warning         In order to prevent unpredictable or undesired behavior of 
 *                  the system, make sure to take all this into consideration when using 
 *                  the WWAN APIs.
 * 
 * @brief           Supported architectures are specified in the configuration
 *                  file (SIM800x_CONFIG.h).
 * @brief           See dependencies in the include section.
 * 
 * @note            History:
 *                   - Feb 18, 2023: Initial release
 * 
 * @note            It has been successfully tested with:
 *                  - IDE: 
 *                      * MPLAB X IDE v5.30
 *                  - Compiler: 
 *                      * XC8 V1.45, V2.36
 *                  - DTE Devices: 
 *                      * PIC 18F452
 *                  - DCE Devices:
 *                      * SIM800L
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; </center></h2>
 *
 *
 ******************************************************************************
 */

#ifndef SIM800X_SDM_H
#define	SIM800X_SDM_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------
#include "SIM800x_CONFIG.h" 
#if defined(CONFIG_TARGET_ARCH_PIC18)
#include "../../../../M8M_APIs/PIC18.X/Inc/USART.h"
#include "../../../../M8M_APIs/PIC18.X/Inc/SystemTime.h"
#include "../../../../M8M_APIs/PIC18.X/Inc/GPIO.h"  
#if (CONFIG_ENABLE_DBG_SUART == 1) 
#include "../../../../M8M_APIs/PIC18.X/Inc/SoftwareUART.h"    
#endif
#elif defined(CONFIG_TARGET_ARCH_AVRMEGA)
#elif defined(CONFIG_TARGET_ARCH_STM32F4)
#endif     
//----------------------------------- 

#if defined (CONFIG_TARGET_ARCH_PIC18)
#define UARTSend(x)                     USARTTransmitByte(x)
#define UARTRead()                      USARTReceiveByte()
#define Tick()                          Tick_ms()
#define TickInit()                      SystimeInit()
#define wait(x)                         Wait_ms(x)
#define SetBr(x)                        USARTSetBaudRate(x)
#define SetPin(x,y)                     GPIOSetPin(x,y)
#define ClearPin(x,y)                   GPIOClearPin(x,y)
#define SetOutput(x,y)                  GPIOSetOutput(x,y)
#define SetInput(x,y)                   GPIOSetInput(x,y)
#if (CONFIG_ENABLE_DBG_SUART == 1)
#define SUARTSend(x)                    SoftUARTTransmitByte(x)
#define SUARTInit()                     SoftUARTInit()
#define SUARTPrint(x)                   SoftUARTPrint(x)
#endif
#elif defined (CONFIG_TARGET_ARCH_AVRMEGA)
#elif defined (CONFIG_TARGET_ARCH_STM32F4)
#endif    
//-----------------------------------    
/**
 * @brief   Initialize and enable the SDM driver
 * @note    This function will:
 *              - Enable all required device UART interrupt settings, depending on the architecture
 *              - Set communication baudrate
 *              - Initialize the system time management library 
 *              (ex. System Tick for STM32, SystemTime for PIC18)
 * 
 * @note    Prior to using this function, make sure to define the global macro FOSC_MHZ or the OSC_MHZ (in SystemTime.h)
 *          constant, with the MCU crystal frequency in megahertz.
 * @param   br: UART communication baud rate constant value   
 * @retval  none
 * 
 * @warning **When using the SDM on PIC18 devices, make sure not to let the RX pin floating. Use a pull-up instead.** 
 */ 
extern void SIM800xSDMInit(uint32_t br);  
//-----------------------------------    

//-----------------------------------
/**
 * @brief   Enable SDM data reception over the UART
 * @param   none
 * @retval  none
 * @note    **This function will enable the interrupt driven data reception.**
 */
extern void SIM800xSDMResume(void);   
//-----------------------------------

//-----------------------------------
/**
 * @brief   Disable SDM data reception over the UART
 * @param   none
 * @retval  none
 * @note    This function will disable the interrupt driven data reception.
 * @note    **The SDM can send command to the modem, but cannot receive responses.**
 */
extern void SIM800xSDMSuspend(void);   
//-----------------------------------

//-----------------------------------
/**
 * @brief   Checks if the SDM data reception over the UART is enabled
 * @param   none
 * @retval  
 *          - 1: suspended
 *          - 0: not suspended
 * 
 */
extern uint8_t SIM800xSDMIsSuspended(void);   
//-----------------------------------

//-----------------------------------
/**
 * @brief   Get the amount of data bytes available in the receive FIFO
 * @param   none
 * @retval  byte count
 *        
 */
extern uint16_t SIM800xSDMRxAvailable(void);                                          
//-----------------------------------

//-----------------------------------
/**
 * @brief   Send a byte to the modem via UART
 * @param   data: byte to send
 * @retval  none 
 * 
 */
extern void SIM800xSDMSendByte(uint8_t data);                                                                                 
//-----------------------------------

//-----------------------------------
/**
 * @brief       Send a series of bytes over the UART
 * @param[in]   data : data to send
 * @param[in]   cnt: number of bytes to write
 * @retval      none 
 * 
 */
extern void SIM800xSDMSendBytes(uint8_t *data, uint16_t cnt);                                         
//-----------------------------------

//-----------------------------------
/**
 * @brief   Sends a null-terminated string over the UART 
 * @param   str : string to send
 * @retval  none 
 * 
 */
extern void SIM800xSDMPrint(const char *str);                                         
//-----------------------------------

//-----------------------------------
/**
 * @brief   Read and remove the byte available at the current receive FIFO pointer index
 * @note    Make sure to check data availability using SIM800xSDMRxAvailable() before 
 *          calling this function.
 * @param   none
 * @retval          
 *              - byte read
 *              - 0xFF: No data available      
 */
extern uint8_t SIM800xSDMReadByte(void);   
//-----------------------------------

//-----------------------------------
/**
 * @brief       Read and remove the bytes available in the receive FIFO,
 *              starting at the current pointer index.
 * @param[out]  data: byte array to copy data to. 
 * @param[in]   cnt: number of bytes to read
 * @param[in]   tout: time-out value
 * @retval      number of bytes read
 *      
 */
extern uint16_t SIM800xSDMReadBytes(uint8_t *data, uint16_t cnt, uint32_t tout);   
//-----------------------------------

//-----------------------------------
/**
 * @brief   Read the byte available at the specified receive FIFO pointer index.
 *          Index is 0-based, starting at the current position to the index of the
 *          last byte available.
 *  
 * @param   idx: 0-based index
 * @retval  
 *              - byte read
 *              - 0xFF: No data available
 *      
 */
extern uint8_t SIM800xSDMPeek(uint8_t idx);   
//-----------------------------------

//-----------------------------------
/**
 * @brief       Extract the [DATA] portion of the next received packet from the 
 *              input FIFO, and remove the packet from the buffer.
 * @note        **packet format: [SOF] [DATA] [EOF]** 
 * @param[out]  data: byte array, to copy the [DATA] in. 
 * @retval  
 *          - size of [DATA]  
 *          - 0: no packet received
 *          - 0: invalid packet
 *          - -1: Time-out
 *       
 */
extern int SIM800xSDMReadF1Pkt(uint8_t *data);   
//-----------------------------------

//-----------------------------------
/**
 * @brief       Extract the [DATA] portion of the next received packet from the 
 *              input FIFO, and remove the packet from the buffer.
 * @note        **packet format:  [DATA] [SOF] [EOF]** 
 * @param[out]  data: byte array, to copy the [DATA] 
 * @retval  
 *          - size of [DATA] or  
 *          - 0: no packet received
 *          - 0: invalid packet
 *          - -1: Time-out
 *       
 */
extern int SIM800xSDMReadF2Pkt(uint8_t *data);   
//-----------------------------------

//-----------------------------------
/**
 * @brief       Flush receive FIFO
 * @param       none
 * @retval      none 
 */
extern void SIM800xSDMFlush(void);                                     
//-----------------------------------

//-----------------------------------
/**
 * @brief       Set SDM operation time-out
 * @param       tout: time-out value in ms
 * @warning     It is not recommend to use this function directly, unless
 *              explicitly specified by a given API.
 * 
 * @retval      none 
 */
extern void SIM800xSDMSetTimeOut(uint32_t tout);                                     
//-----------------------------------

//-----------------------------------
/**
 * @brief       Get SDM operation time-out
 * @param       none
 * @retval      time-out value 
 */
extern uint32_t SIM800xSDMGetTimeOut(void);                                     
//-----------------------------------

//-----------------------------------
/**
 * @brief   SDM interrupt call-back function
 * @param   none
 * @retval  none
 * @note:   This function should be inserted in the global interrupt ISR function (if shared ISR vector)
 *          or linked to the UART/USART receive interrupt vector. 
 *
 */
extern void SIM800xSDMCallBack(void);
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* SIM800X_SDM_H */

