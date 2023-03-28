# Description
The SIM800xPIC18 API, part of the **WWM (Wireless WAN Modems Access APIs package)**, is a piece of reusable software developed at #Firmware Engineers as part of the #IoT Solution Demo initiative.
It is intended to provide comprehensive, low memory footprint and fully tested framework that exposes the complete functionalities of SIM800 series modems, to be used in IoT applications that may be using PIC18 architectures for implementing devices or lighweight gateways.
## Included functionalities 
The current version of this software includes the following APIs:
- HTTP
- GPRS
- IP
- Modem control
- ID number
## Notes 
Subsequent versions targeting AVR and STM32 architectures will be created overtime. All source files are self-documenting and doxygen compatible, so a full and efficient API documentation can be generated. The diagram below shows the API architecture.
![WWAN API Architecture](https://user-images.githubusercontent.com/56833496/228084512-9d896a2e-55bf-46ae-9788-7c86f418de86.png)
# Prerequisites
To use this software you need to:
- Install MPLAB X IDE: https://www.microchip.com/en-us/tools-resources/archives/mplab-ecosystem
- C compiler for PIC 18 microcontrollers (ex. XC8): https://www.microchip.com/en-us/tools-resources/archives/mplab-ecosystem
- Doxygen generator, to generate documentation from source code (optional): https://www.doxygen.nl/download.html
# Demonstration
This repository includes a demo Data Logger application (by implementing a lightweight REST API Client), that illustrate the usage of the SIM800x API, with a SIM800L modem and a PIC18F452. Following is a simplified diagram of it's operation.
![Demo Diagram](https://user-images.githubusercontent.com/56833496/228093675-567eda01-144b-449e-a2c9-35b34626fe87.png)
## Additional requirements for the demo
- SIMCOM SIM800L-based board (ex. **SIM800L EVB**)
- PIC18F based board (I used a custom-made prototyping board on which I mounted the PIC18F452 controller)
- A USB to UART/USART converter (I used a FTDI 232R board) 
## Software configurations
- **Debug channel**
  * Baudrate: **9600, fixed**
  * Transmit Pin: **PORTB[3]**
  * Receive Pin: **PORTB[0]**
  
- **Control channel**
  * Baudrate: Configurable via **SIM800xInit()** function
  * Transmit Pin: **USART module PORTC[6]**
  * Receive Pin: **USART module PORTC[7]**
 More details are specified in the self-documenting source files. 
 ## Demo Terminal view
 ![Terminal Debug](https://user-images.githubusercontent.com/56833496/228094534-d637de5d-9469-4758-b524-35de17d43ce1.PNG)
 ## Demo Dashboard
 ![Thinger Device Dashboard](https://user-images.githubusercontent.com/56833496/228094586-e9fcad51-3d1c-4659-a562-272b869b74d9.PNG)
 ## Demo Device settings
 ![Thinger Device Setting](https://user-images.githubusercontent.com/56833496/228094601-8b6a0d82-ba32-4e89-ba74-f9ce380e7f39.PNG)
 ## Demo Bucket (Random Values)
 ![Thinger Bucket](https://user-images.githubusercontent.com/56833496/228094617-a2c5277d-f531-463f-9a83-45566c521523.PNG)
 ## Image
 ![Demo Image](https://user-images.githubusercontent.com/56833496/228095413-05870821-6217-4c71-a149-36a2648d7ade.jpg)
# Team
This file is currently being developed by the #Firmware-Engineers team. Contributions, recommendations and any sort of feedback are more than welcome.
# License






