/**
 ******************************************************************************
 * @file            SIM800x_IP.h
 * @author          Maxime  
 * @brief           Header file for SIM800 series modems IP application
 * @brief           This file provides function definitions used for activating
 *                  applications based on IP (Internet Protocol), such as MQTT, 
 *                  FTP, HTTP and GSM Location.
 * 
 * @brief           Supported devices are listed below.
 * @brief           See dependencies in the include section.
 * 
 * @note            History:
 *                   - March 4, 2023: Initial release
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

#ifndef SIM800X_IP_H
#define	SIM800X_IP_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------
#include <stdlib.h>
#include "SIM800x_Types.h"    
//-----------------------------------

/**
  * @brief  IP status type definition
  */ 
typedef enum
{
    //---------
    CONNECTING          = 0,                                                    //!< Bearer connecting 
    CONNECTED           = 1,                                                    //!< Bearer connected
    CLOSING             = 2,                                                    //!< Bearer closing
    CLOSED              = 3                                                     //!< Bearer closed       
    //---------        
}SIM800xIPStatusType;
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Set bearer connection type parameter
 * @param   cid: bearer profile id. Supported values are:
 *              - [1...3]  
 * 
 * @param   contype: connection type (null terminated string). Supported values are:
 *              - "CSD"
 *              - "GPRS"   
 *    
 * @retval  APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no response from the modem
 *              - ERROR: connection type error  
 */ 
extern APIStatusType SIM800xIPSetConnectionType(uint8_t cid, const char* contype);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Set bearer APN parameter
 * @param   cid: bearer profile id. Supported values are:
 *              - [1...3]   
 * 
 * @param   apn: bearer APN (null terminated string).
 * @note    **Maximum size for APN is 64 character.** 
 * @retval  APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no response from the modem
 *              - ERROR: APN error  
 */ 
extern APIStatusType SIM800xIPSetAPN(uint8_t cid, const char* apn);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Set bearer user parameter
 * @param   cid: bearer profile id. Supported values are:
 *              - [1...3]   
 * 
 * @param   user: bearer user (null terminated string).
 * @note    **Maximum size for USER is 32 character.**  
 * @retval  APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no response from the modem
 *              - ERROR: user name error  
 */ 
extern APIStatusType SIM800xIPSetUser(uint8_t cid, const char* user);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Set bearer password parameter
 * @param   cid: bearer profile id. Supported values are:
 *              - [1...3]   
 * 
 * @param   pw: bearer password (null terminated string).
 * @note    **Maximum size for PW is 32 character.**
 * @retval  APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no response from the modem
 *              - ERROR: password error  
 */ 
extern APIStatusType SIM800xIPSetPassword(uint8_t cid, const char* pw);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Set bearer Circuit-Switched Data Call (CSD) Phone Number parameter
 * @param   cid: bearer profile id. Supported values are:
 *              - [1...3]  
 * 
 * @param   pn: bearer CSD phone number (null terminated string).
 * @note    **Maximum size for PN is 20 character.** 
 * @retval  APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no response from the modem
 *              - ERROR: phone number error  
 */ 
extern APIStatusType SIM800xIPSetPhoneNumber(uint8_t cid, const char* pn);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Set bearer CSD rate parameter
 * @param   cid: bearer profile id. Supported values are:
 *              - [1...3]   
 * 
 * @param   rate: bearer CSD rate. Supported values are:
 *              - 2400
 *              - 4800
 *              - 9600
 *              - 14400    
 * 
 * @retval  APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no response from the modem
 *              - ERROR: CSD rate error  
 */ 
extern APIStatusType SIM800xIPSetRate(uint8_t cid, uint16_t rate);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Activate bearer context
 * @param   cid: bearer context id. Supported values are:
 *              - [1...3]   
 *    
 * @retval  APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT:  time-out
 *              - ERROR: failed 
 */ 
extern APIStatusType SIM800xIPOpen(uint8_t cid);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Deactivate bearer context
 * @param   cid: bearer context id. Supported values are:
 *              - [1...3]   
 *    
 * @retval  APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: time-out
 *              - ERROR: failed  
 */ 
extern APIStatusType SIM800xIPClose(uint8_t cid);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get bearer context state
 * @param       cid: bearer profile id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  ip: bearer IP address (null terminated string).
 * @param       If the bearer context is not activated, a null IP address will be returned.     
 *    
 * @retval      SIM800xIPStatusType (See description)
 *   
 */ 
extern SIM800xIPStatusType SIM800xIPGetState(uint8_t cid, char* ip);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get bearer profile parameters
 * @param[in]   cid: bearer profile id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  contype: connection type parameter
 * @param[out]  apn: APN parameter    
 * @param[out]  pn: phone number parameter 
 * @param[out]  user: user parameter
 * @param[out]  pw: password parameter
 * @param[out]  rate: CSD rate parameter 
 * 
 * @note        All the above parameters are null terminated strings. 
 * @retval      APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: time-out
 *   
 */ 
extern APIStatusType SIM800xIPGetParameters(uint8_t cid, char* contype, char* apn, char* pn, char* user, char* pw, uint16_t* rate);  
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* SIM800X_IP_H */

