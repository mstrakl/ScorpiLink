#ifndef SCORPIOTEL_UTILS_H
#define SCORPIOTEL_UTILS_H

#include <Arduino.h>

#define START_BYTE 0x55
#define HEADER_LEN 4
#define PAYLOAD_LEN 16
#define CRC_LEN 2


namespace ScorpioTel {
    namespace Utils {

        #pragma pack(push,1)
        struct ScorpioPacket {
            uint8_t startByte;
            uint8_t version;
            uint8_t packetLength;
            uint8_t deviceId;
            uint8_t payload[PAYLOAD_LEN];
            //uint8_t crc[CRC_LEN];
            uint16_t crc;
            //uint16_t crc_calc;
        };
        #pragma pack(pop)


        #pragma pack(push,1)
        struct ScorpioLog {
            uint8_t _timeSincePowerOnMillis[3];
            uint8_t throttle;
            uint16_t current;
            uint16_t voltage;
            uint16_t consumption;
            uint8_t temperature;
            uint8_t power;
            uint8_t becVoltage;
            uint16_t rpm;
            uint8_t err;
        };
        #pragma pack(pop)


        // Function to print the contents of the ScorpioPacket
        void printScorpioPacket(const Utils::ScorpioPacket &packet) {
            // Print start uint8_t (in HEX format)
            Serial.print("Start Byte: 0x");
            Serial.println(packet.startByte, HEX);

            // Print version uint8_t
            Serial.print("Version: ");
            Serial.println(packet.version, DEC);

            // Print packet length
            Serial.print("Packet Length: ");
            Serial.println(packet.packetLength, DEC);

            // Print device ID
            Serial.print("Device ID: ");
            Serial.println(packet.deviceId, DEC);

            // Print payload array (in HEX)
            Serial.println("Payload: ");
            for (int i = 0; i < PAYLOAD_LEN; i++) {
                Serial.print("0x");
                if (packet.payload[i] < 0x10) {  // For better readability with single-digit hex
                Serial.print("0");
                }
                Serial.print(packet.payload[i], HEX);
                Serial.print(" ");
            }
            Serial.println();  // New line after payload

            // Print CRC array (in HEX)
            Serial.print("CRC: ");
            Serial.println(packet.crc, HEX);
            //Serial.print("CRC Cx: ");
            //Serial.println(packet.crc_calc, HEX);

            Serial.print("CRC: ");
            Serial.println(packet.crc);
            //Serial.print("CRC Cx: ");
            //Serial.println(packet.crc_calc);
            
            Serial.println();  // New line after CRC
        }



    }
}

#endif