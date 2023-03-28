/**
 ******************************************************************************
 * @file            SIM800x_ID.h
 * @author          Maxime  
 * @brief           Header file for SIM800 series modems ID numbers
 * @brief           This file provides function definitions used for requesting 
 *                  some ID numbers from the modem.
 * 
 * @note            IDs include:
 *                      - Manufacturer ID
 *                      - Model ID
 *                      - Revision ID of Software Release
 *                      - Global Object ID
 *                      - Serial Number ID or IMEI
 * 
 * @brief           Supported devices are listed below.
 * @brief           See dependencies in the include section.
 * 
 * @note            History:
 *                   - March 3, 2023: Initial release
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

#ifndef SIM800X_ID_H
#define	SIM800X_ID_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------
#include <stdlib.h>
#include "SIM800x_Types.h"    
//-----------------------------------

    
//-----------------------------------    
/**
 * @brief   Request Manufacturer ID
 * @param   id: requested id (null terminated string)
 * @note    **Min array size for id is 11**  
 * @retval  SIM800xStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no data received
 *              - INVALID_RESPONSE: invalid
 *              - NOT_DEFINED: unexpected response    
 *
 */ 
extern APIStatusType SIM800xGetManufacturerID(char * id);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Request Model ID
 * @param   id: requested id (null terminated string)
 * @note    **Min array size for id is 15**  
 * @retval  SIM800xStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no data received
 *              - INVALID_RESPONSE: invalid
 *              - NOT_DEFINED: unexpected response  
 *
 */ 
extern APIStatusType SIM800xGetModelID(char * id);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Request Software Revision ID
 * @param   id: requested id (null terminated string)
 * @note    **Min array size for id is 15**  
 * @retval  SIM800xStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no data received
 *              - INVALID_RESPONSE: invalid
 *              - NOT_DEFINED: unexpected response  
 *
 */ 
extern APIStatusType SIM800xGetSoftwareRevisionID(char * id);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Request Global Object ID
 * @param   id: requested id (null terminated string)
 * @note    **Min array size for id is 7**  
 * @retval  SIM800xStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no data received
 *              - INVALID_RESPONSE: invalid
 *              - NOT_DEFINED: unexpected response   
 *
 */ 
extern APIStatusType SIM800xGetGlobalObjectID(char * id);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Request Serial Number ID or IMEI (International Mobile Equipment Identity number)
 * @param   id: requested id (null terminated string)
 * @note    **Min array size for id is 16**  
 * @retval  SIM800xStatusType
 * 
 *              - OK: success 
 *              - TIME_OUT: no data received
 *              - INVALID_RESPONSE: invalid
 *              - NOT_DEFINED: unexpected response   
 *
 */ 
extern APIStatusType SIM800xGetIMEI(char * id);  
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* SIM800X_ID_H */

