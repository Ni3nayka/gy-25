/*
   arduino library for gy-25 module:
   https://github.com/Ni3nayka/gy-25

   author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka
   write:  May 2024
   modify: May 2024
*/  

#pragma once

#include "gy-25_basic.h"
#include <SoftwareSerial.h>

class GY25_UART_SOFT: 
  private SoftwareSerial, 
  public GY25 
{
  public:
    void setup(int baud_rate=115200) {
      GY25_UART_SOFT::begin(baud_rate);
      GY25_UART_SOFT::setupBasic();
    }
  private:
    using SoftwareSerial::SoftwareSerial;
    // interface
    int availableGyro() {
      return GY25_UART_SOFT::available();
    }
    int readGyro() {
      return GY25_UART_SOFT::read();
    }
    void writeGyro(int data) {
      GY25_UART_SOFT::write(data);
    }
};