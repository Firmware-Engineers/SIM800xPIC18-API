/**
 ******************************************************************************
 * file:   SIM800x_CONFIG.h
 * author: Maxime
 * @brief  Configuration file for SIM800 series API
 * @brief  This file defines macros and constants used to configure the
 *         API operation.
 * 
 * @brief  Some configurations are:
 *          - COM controls I/O mapping
 *          - Modem power control I/O mapping
 *          - Modem reset I/O mapping
 *          - Target Architecture selection 
 * 
 * @note    History:
 *              - Feb 17, 2023: Initial release
 * 
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; </center></h2>
 *
 *
 ******************************************************************************
 */

#ifndef SIM800X_CONFIG_H
#define	SIM800X_CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

/** @defgroup SIM800X_CONFIG_API_TARGET_ARCH_SELECT API target architecture selection 
 * @{
 *  
 */    
#define SIM800X_CONFIG_TARGET_ARCH_PIC18                                //!< Select 8 bits PIC 18 architecture. See PIC18Types.h file for more details about I/O types constants                     
//#define SIM800X_CONFIG_TARGET_ARCH_AVRMEGA                              //!< Select 8 bits AVR mega architecture.
//#define SIM800X_CONFIG_TARGET_ARCH_STM32F4                              //!< Select 32 bits ARM-based STM32F4.
/**
  * @}
  */
     
/** @defgroup CONFIG_API_OP_CONSTANTS API operation configuration constants
 * @{
 * @note   Set 1 or 0 for respectively enabling or disabling configurations 
 */     
#define SIM800X_CONFIG_USE_HW_FLOW_CTRL_PINS                    0       //!< Determine wether hardware flow control signals (RTS/CTS) are implemented by the API                    
#define SIM800X_CONFIG_USE_PWR_CTRL_PIN                         0       /*!< Determine wether power ON/OFF control is implemented by the API.
                                                                             @note **This is not similar to the modem PWRKEY. The pin is assumed to be connected 
                                                                                    to some kind of supply control circuit (ex. MOSFET gate or voltage regulator EN pin).** */
#define SIM800X_CONFIG_USE_PWRKEY_PIN                           0       //!< Determine wether modem PWRKEY is used by the API    
#define SIM800X_CONFIG_USE_PWR_ACT_LOW_HIGH                     1       //!< Determine wether power ON/OFF control signal is active low or high
#define SIM800X_CONFIG_USE_PWRKEY_ACT_LOW_HIGH                  0       //!< Determine wether PWRKEY control signal is active low or high    
#define SIM800X_CONFIG_USE_RST_CTRL_PIN                         0       //!< Determine wether modem reset is implemented by hardware
#define SIM800X_CONFIG_USE_RST_ACT_LOW_HIGH                     1       //!< Determine wether modem reset signal is active low or high   
#define SIM800X_CONFIG_ENABLE_DBG_SUART                         0       /*!< Determine wether serial debugging using software UART will be used by the API. */      
/**
  * @}
  */

/** @defgroup SIM800X_CONFIG_API_IO_CONSTANTS API I/O configuration constants
 * @{
 *  
 */     
#define SIM800X_CONFIG_MODEM_RST_PORT                           GPIOA   //!< I/O PORTA used for reset control                    
#define SIM800X_CONFIG_MODEM_RST_PIN                            0       //!< I/O PORTA[0] mapped to RST control signal                                    
#define SIM800X_CONFIG_MODEM_PWR_CTRL_PORT                      GPIOA   //!< I/O PORTA used for PWR control                    
#define SIM800X_CONFIG_MODEM_PWR_CTRL_PIN                       1       //!< I/O PORTA[1] mapped to PWR control signal
#define SIM800X_CONFIG_MODEM_CTS_PORT                           GPIOA   //!< I/O PORTA used for CTS signal
#define SIM800X_CONFIG_MODEM_CTS_PIN                            2       //!< I/O PORTA[2] mapped to CTS signal
#define SIM800X_CONFIG_MODEM_RTS_PORT                           GPIOA   //!< I/O PORTA used for RTS signal
#define SIM800X_CONFIG_MODEM_RTS_PIN                            3       //!< I/O PORTA[3] mapped to RTS signal
#define SIM800X_CONFIG_MODEM_PWRKEY_PORT                        GPIOA   //!< I/O PORTA used for PWRKEY signal
#define SIM800X_CONFIG_MODEM_PWRKEY_PIN                         4       //!< I/O PORTA[4] mapped to PWRKEY signal    
/**
  * @}
  */   

#ifdef	__cplusplus
}
#endif

#endif	/* SIM800X_CONFIG_H */

