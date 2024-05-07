/*
   arduino library for gy-25 module:
   https://github.com/Ni3nayka/gy-25

   author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka
   write:  May 2024
   modify: May 2024
*/  

// https://static-eu.insales.ru/files/1/1580/10954284/original/Описание_GY25__курс__крен__тангаж_.pdf
// https://metanit.com/cpp/tutorial/5.10.php

#pragma once

class GY25 {
  public:
    int angle[3];

    // interface
    void setup() {}

    void setupBasic() {
      delay(1000);
      GY25::writeGyro(0XA5);  // request the data
      GY25::writeGyro(0X52);
    }

    void calibration() {
      // setup time
      delay(3000);
      // Kalibrasi Tilt
      GY25::writeGyro(0xA5);
      GY25::writeGyro(0x54);
      // Jeda sebelum kalibrasi heading
      delay(1000);
      // Kalibrasi Heading
      GY25::writeGyro(0xA5);
      GY25::writeGyro(0x55);
      delay(100);
    }

    void update() {
      while (GY25::availableGyro()) {
        GY25::Re_buf[GY25::counter] = (unsigned char)GY25::readGyro();
        if (GY25::counter == 0 && GY25::Re_buf[0] != 0xAA) return;
        GY25::counter++;
        if (GY25::counter == 8) {
          GY25::counter = 0;
          GY25::sign = 1;
        }
      }
      if (GY25::sign) {
        GY25::sign = 0;
        if (GY25::Re_buf[0] == 0xAA && GY25::Re_buf[7] == 0x55) {
          GY25::angle[0] = (GY25::Re_buf[1] << 8 | GY25::Re_buf[2]) / 100;
          GY25::angle[1] = (GY25::Re_buf[3] << 8 | GY25::Re_buf[4]) / 100;
          GY25::angle[2] = (GY25::Re_buf[5] << 8 | GY25::Re_buf[6]) / 100;
          //GY25::print();
        }
      }
    }

    void printData() {
      Serial.print(GY25::angle[0]);
      Serial.print(" ");
      Serial.print(GY25::angle[1]);
      Serial.print(" ");
      Serial.print(GY25::angle[2]);
      Serial.println();
    }
  private:
    unsigned char counter = 0;  //buffer where the received data will be stored
    unsigned char sign = 0;
    unsigned char Re_buf[8];

    // interface
    int availableGyro() {
      return 0;
    }
    int readGyro() {
      return 0;
    }
    void writeGyro(int data) {}
};