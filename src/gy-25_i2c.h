/*
   arduino library for gy-25 module:
   https://github.com/Ni3nayka/gy-25

   author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka
   write:  May 2024
   modify: May 2024
*/  

#pragma once

#include <SoftwareSerial.h>

class GY25_I2C: public GY25 {
public:

  void setup(int i2c_address=0) {
    GY25_I2C::setupBasic();
  }
private:
    // interface
    int availableGyro() {
      // return GY25_UART_SOFT::available();
    }
    int readGyro() {
      // return GY25_UART_SOFT::read();
    }
    void writeGyro(int data) {
      // GY25_UART_SOFT::write(data);
    }
};