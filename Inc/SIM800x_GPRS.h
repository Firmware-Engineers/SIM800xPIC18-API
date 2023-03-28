/**
 ******************************************************************************
 * @file            SIM800x_GPRS.h
 * @author          Maxime  
 * @brief           Header file for SIM800 series modems GPRS application
 * @brief           This file provides function definitions that provide GPRS 
 *                  services.
 * 
 * @brief           Supported devices are listed in the include section.
 * @brief           See dependencies in the include section.
 * 
 * @note            History:
 *                   - March 6, 2023: Initial release
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

#ifndef SIM800X_GPRS_H
#define	SIM800X_GPRS_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------
#include <stdlib.h>
#include "SIM800x_Types.h"    
//-----------------------------------

/**
  * @brief  GPRS status type definition
  */ 
typedef enum
{
    //---------
    DETACHED                    = 0,                                            //!< GPRS service detached 
    ATTACHED                    = 1,                                            //!< GPRS service attached 
    DEACTIVATED                 = 0,                                            //!< PDP context deactivated
    ACTIVATED                   = 1,                                            //!< PDP context activated 
    DISABLED                    = 0,                                            //!< Disabled
    ENABLED                     = 1,                                            //!< Enabled
    NOT_REGISTRED               = 0,                                            //!< Not registered
    REGISTERED_HOME             = 1,                                            //!< Registered, home network
    NOT_REGISTRED_SEARCHING     = 2,                                            //!< Not registered, searching
    REGISTRATION_DENIED         = 3,                                            //!< Registration denied
    UNKNOWN                     = 4,                                            //!< Unknown
    REGISTRED_ROAMING           = 5,                                            //!< Registered, roaming
    PACKET_DOMAIN               = 0,                                            //!< Packet Domain (GPRS)
    CIRCUIT_SWITCHED            = 1,                                            //!< Circuit Switched Data Call (CSD)
    PACKET_DOMAIN_PREFERRED     = 2,                                            //!< Packet Domain preferred (CSD used if GPRS not available)
    CIRCUIT_SWITCHED_PREFERRED  = 3,                                            //!< Circuit Switched preferred (GPRS used if circuit switched not available)                    
    GPRS_TIME_OUT               = 6,                                            //!< Time-out
    GPRS_CME_ERROR              = 7,                                            //!< ME error        
    //---------        
}SIM800xGPRSStatusType;
//-----------------------------------    

//-----------------------------------    
/**
 * @brief       Get GPRS service attachment state
 * @param       none      
 * @retval      SIM800xGPRSStatusType (See description). Supported values are:
 * 
 *              - ATTACHED: GPRS attached 
 *              - DETACHED: GPRS detached
 *              - GPRS_TIME_OUT: No response
 *  
 */ 
extern SIM800xGPRSStatusType SIM800xGPRSGetAttachState(void);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Attach GPRS service
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)      
 * @retval      APIStatusType. Supported values are:
 * 
 *              - OK: success 
 *              - TIME_OUT: time-out
 *              - ERROR: failed
 *              - CME_ERROR: ME error
 *  
 */ 
extern APIStatusType SIM800xGPRSAttach(uint16_t* errcode);   
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Detach GPRS service
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)      
 * @retval      APIStatusType. Supported values are:
 * 
 *              - OK: success 
 *              - TIME_OUT: time-out
 *              - CME_ERROR: ME error
 *  
 */ 
extern APIStatusType SIM800xGPRSDetach(uint16_t* errcode);   
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set PDP context parameters
 * @param[in]   cid: PDP context id. Supported values are:
 *              - [1...3]   
 * 
 * @param[in]   apn: Access Point Name (null terminated string).
 * @note        **Maximum size for APN is 50 character.**
 * @retval      APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no response from the modem
 *              - ERROR: failed  
 */ 
extern APIStatusType SIM800xGPRSSetPDPContext(uint8_t cid, const char* apn);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set Quality of Service (QoS) minimum acceptable
 * @param[in]   cid:  PDP context id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  precedence: QoS precedence class. Supported values are:
 *              - [0...3]
 * 
 * @param[out]  delay: QoS delay. Supported values are:  
 *              - [0...4]
 *   
 * @param[out]  reliability: QoS reliability. Supported values are:
 *              - [0...5]
 *  
 * @param[out]  peak: QoS peak. Supported values are:
 *              - [0...9]
 * 
 * @param[out]  mean: QoS mean. Supported values are:
 *              - [0...18, 31] 
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *  
 * @retval      APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: time-out
 *              - CME_ERROR: ME error
 *   
 */ 
extern APIStatusType SIM800xGPRSSetQoSMin(uint8_t cid, uint8_t precedence, uint8_t delay, uint8_t reliability, uint8_t peak, uint8_t mean, uint16_t* errcode);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set Quality of Service (QoS) request 
 * @param[in]   cid:  PDP context id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  precedence: QoS precedence class. Supported values are:
 *              - [0...3]
 * 
 * @param[out]  delay: QoS delay. Supported values are:  
 *              - [0...4]
 *   
 * @param[out]  reliability: QoS reliability. Supported values are:
 *              - [0...5]
 *  
 * @param[out]  peak: QoS peak. Supported values are:
 *              - [0...9]
 * 
 * @param[out]  mean: QoS mean. Supported values are:
 *              - [0...18, 31] 
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *  
 * @retval      APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: time-out
 *              - CME_ERROR: ME error
 *   
 */ 
extern APIStatusType SIM800xGPRSSetQoSRequest(uint8_t cid, uint8_t precedence, uint8_t delay, uint8_t reliability, uint8_t peak, uint8_t mean, uint16_t* errcode);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get PDP context activation state
 * @param       cid:  PDP context id. Supported values are:
 *              - [1...3]  
 *     
 * @retval      SIM800xGPRSStatusType (See description). Supported values are:
 * 
 *              - ACTIVATED: PDP context activated
 *              - DEACTIVATED: PDP context deactivated
 *              - GPRS_TIME_OUT: No response
 *  
 */ 
extern SIM800xGPRSStatusType SIM800xGPRSGetPDPContextState(uint8_t cid);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Activate PDP context
 * @param[in]   cid: PDP context id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *    
 * @retval      APIStatusType. Supported values are:
 * 
 *              - OK: success 
 *              - TIME_OUT: time-out
 *              - ERROR: failed
 *              - CME_ERROR: ME error
 *  
 */ 
extern APIStatusType SIM800xGPRSPDPContextActivate(uint8_t cid, uint16_t* errcode);   
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Deactivate PDP context
 * @param[in]   cid: PDP context id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *       
 * @retval      APIStatusType. Supported values are:
 * 
 *              - OK: success 
 *              - TIME_OUT: time-out
 *              - ERROR: failed    
 *              - CME_ERROR: ME error
 *  
 */ 
extern APIStatusType SIM800xGPRSPDPContextDeactivate(uint8_t cid, uint16_t* errcode);   
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Enter data mode
 * @param[in]   cid:  PDP context id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h) 
 *  
 * @retval      APIStatusType
 * 
 *              - OK: Data mode set 
 *              - TIME_OUT: no response 
 *              - CME_ERROR: ME error    
 *   
 */ 
extern APIStatusType SIM800xGPRSSetDataMode(uint8_t cid, uint16_t* errcode);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get PDP address
 * @param       cid:  PDP context id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  ip: IP address (null terminated string).
 * @param       If the PDP context is not activated, a null address will be returned.     
 *    
 * @retval      APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no response 
 *              - ERROR: failed
 *   
 */ 
extern APIStatusType SIM800xGPRSGetAddress(uint8_t cid, char* ip);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get Mobile Station (MS) Class
 * @param[out]  mtclass: MS Class. Supported values are:
 *              - 1: MS Class B
 *              - 2: MS Class CG
 *              - 3: MS Class CC
 *       
 * @retval      APIStatusType. Supported values are:
 * 
 *              - OK: success 
 *              - TIME_OUT: time-out
 *  
 */ 
extern APIStatusType SIM800xGPRSGetMTClass(uint8_t* mtclass);   
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get Mobile Station (MS) Class
 * @param[in]   mtclass: MS Class. Supported values are:
 *              - 1: MS Class B
 *              - 2: MS Class CG
 *              - 3: MS Class CC
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h) 
 *      
 * @retval      APIStatusType. Supported values are:
 * 
 *              - OK: success 
 *              - TIME_OUT: time-out
 *              - CME_ERROR: ME error
 *  
 */ 
extern APIStatusType SIM800xGPRSSetMTClass(uint8_t mtclass, uint16_t* errcode);   
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get GPRS Unsolicited Event Reporting (UER) mode    
 *    
 * @retval      SIM800xGPRSStatusType
 * 
 *              - ENABLED: GPRS UER enabled 
 *              - DISABLED: GPRS UER disabled 
 *              - GPRS_TIME_OUT: time-out
 * 
 */ 
extern SIM800xGPRSStatusType SIM800xGPRSUERGetMode(void);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set GPRS Unsolicited Event Reporting (UER) state
 * @param[in]   cid: bearer profile id. Supported values are:
 *              - [1...3]   
 * 
 * @param[in]   mode: Supported values are:
 *              - 0: Disable
 *              - 1: Enable
 *   
 * @retval      APIStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no response 
 *              - ERROR: failed  
 * 
 */ 
extern APIStatusType SIM800xGPRSUERSetMode(uint8_t mode);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get GPRS network registration status          
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *       
 * @retval      SIM800xGPRSStatusType. Supported values are:
 * 
 *              - NOT_REGISTRED: not registered 
 *              - REGISTERED_HOME: registered, home network.
 *              - NOT_REGISTRED_SEARCHING: searching for an operator to register to.
 *              - REGISTRATION_DENIED: GPRS disabled. Attachment not allowed.
 *              - UNKNOWN: unknown
 *              - REGISTRED_ROAMING: roaming
 *              - GPRS_TIME_OUT: time-out
 *              - GPRS_CME_ERROR: ME error  
 *  
 */ 
extern SIM800xGPRSStatusType SIM800xGPRSGetNRegState(uint16_t* errcode);   
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Enable GPRS network registration Unsolicited Result Code (URC)
 * @param[in]   urc: URC enable setting. Supported values are:
 *              - 0: Disable network registration URC
 *              - 1: Enable network registration URC
 *              - 2: Enable network registration and location information URC
 *       
 * @retval      APIStatusType. Supported values are:
 * 
 *              - OK: success 
 *              - TIME_OUT: no response
 *              - ERROR: failed
 *  
 */ 
extern APIStatusType SIM800xGPRSURCEnable(uint8_t urc);   
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get GPRS service used for Mobile Originated (MO) Short Message Service (SMS)         
 * @param       none      
 * @retval      SIM800xGPRSStatusType. Supported values are:
 * 
 *              - PACKET_DOMAIN: GPRS  
 *              - CIRCUIT_SWITCHED: CSD 
 *              - PACKET_DOMAIN_PREFERRED: GPRS preferred, CSD alternative
 *              - CIRCUIT_SWITCHED_PREFERRED: CSD preferred, GPRS alternative
 *              - GPRS_TIME_OUT: time-out
 *  
 */ 
extern SIM800xGPRSStatusType SIM800xGPRSGetMOSMSService(void);   
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Enable GPRS network registration Unsolicited Result Code (URC)
 * @param[in]   service: MO SMS service setting. Supported values are:
 *              - 0: Packet Domain
 *              - 1: Circuit Switched (CSD)
 *              - 2: Packet Domain preferred (CSD used if GPRS not available)
 *              - 3: Circuit Switched preferred (GPRS used if circuit switched not available)
 *          
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *       
 * @retval      APIStatusType. Supported values are:
 * 
 *              - OK: success 
 *              - TIME_OUT: no response
 *              - CME_ERROR: ME error
 *  
 */ 
extern APIStatusType SIM800xGPRSSetMOSMSService(uint8_t service, uint16_t* errcode);   
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* SIM800X_GPRS_H */

