// https://static-eu.insales.ru/files/1/1580/10954284/original/Описание_GY25__курс__крен__тангаж_.pdf
// https://metanit.com/cpp/tutorial/5.10.php

#pragma once

#include "gy-25.h"
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