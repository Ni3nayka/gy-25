/*
   arduino library for gy-25 module:
   https://github.com/Ni3nayka/gy-25

   author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka
   write:  May 2024
   modify: May 2024
*/  

#pragma once

#include "gy-25_basic.h"

class GY25_UART: public GY25 {
public:
  void setup(HardwareSerial* serial = &Serial, int baud_rate=115200) {
	  GY25_UART::serial = serial;
    GY25_UART::serial->begin(baud_rate);
    GY25_UART::setupBasic();
  }
private:
  HardwareSerial* serial;
  int availableGyro() {
    return GY25_UART::serial->available();
  }
  int readGyro() {
    return GY25_UART::serial->read();
  }
  void writeGyro(int data) {
    GY25_UART::serial->write(data);
  }
};