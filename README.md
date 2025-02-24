# ScorpiLink – ESP32 Telemetry Converter  
**ScorpiLink** is an ESP-based telemetry converter that translates **Scorpion's Unsolicited Protocol** into **Crossfire Telemetry**, which is supported by **OpenTx** and **EdgeTx** Transmitters.

## Features  
- Converts telemetry data from **Scorpion ESCs** to **Crossfire**.  
- Runs on an **ESP hardware**
  
## Requirements  
- **ESP12-E/F**, or **Node-Mcu** development board
- **Scorpion Tribunus ESC** with telemetry output  
- **Crossfire-compatible receiver**  

## Installation  
1. Flash the firmware to your ESP device.  
2. Connect the **Scorpion ESC telemetry output** signal to **ESP Rx pin (GPIO3)**. Scorpion ESC must be configured to **Unsolicited Mode**, expected baud rate is **38400**
3. Connect the **ESP GPIO2 (Serial1 Tx)** to the **Crossfire receiver Rx Pin**. Expected baud rate is **420000**.

## License  
This project is open-source. Feel free to modify and contribute!  
