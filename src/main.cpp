#include <Arduino.h>
#include <crsffront.h>
#include <ScorpioTel.h>

ScorpioTel::ScorpioTel ScnTel;
CrsfFront::CrsfTelemetry Crsf;

unsigned long time0 = millis();

int i_send = 10; // 10 - send packet esc
                 // 20 - send packet temperatue (via roll-pitch-yaw)

#define BATT_CAP 4500.0 // mAh

void setup()
{
  Serial.begin(38400);
  delay(10);

  ScnTel.init();
  delay(10);

  Serial1.begin(CRSF_BAUDRATE, SERIAL_8N1, SERIAL_TX_ONLY, 2);
  delay(10);
  
  Crsf.begin(Serial1);
  delay(10);


}


void loop() {

  for (int i = 0; i<30; i++) {
    ScnTel.read();
    if (not Serial.available()) break;
  }

  if (millis() - time0 > 100){

    const float time_seconds = 0.1*millis();

    if (i_send == 10) {
      float remaining = BATT_CAP - (float)ScnTel.getConsumption();
      remaining /= BATT_CAP;
      remaining *= 100.0;

      Crsf.sendEscData(ScnTel.getBatteryVoltage(),
                       ScnTel.getCurrent(),
                       (float)ScnTel.getConsumption(),
                       remaining);

      i_send = 20;

    } else if (i_send == 20) {

      Crsf.sendEscTemperature(ScnTel.getTemperature(),
                              sin(time_seconds));

      i_send = 10;
    }



    //Serial.println(" Voltage: " + String(ScnTel.getBatteryVoltage()));
    //Serial.println(" Current: " + String(ScnTel.getCurrent()));
    //Serial.println("    Temp: " + String(ScnTel.getTemperature()));
    //Serial.println("     Rpm: " + String(ScnTel.getRpm()));
    //Serial.println();

    time0 = millis();
  }


}
