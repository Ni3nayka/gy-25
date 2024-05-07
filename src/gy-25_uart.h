// https://static-eu.insales.ru/files/1/1580/10954284/original/Описание_GY25__курс__крен__тангаж_.pdf
// https://metanit.com/cpp/tutorial/5.10.php

#pragma once

#include "gy-25.h"

class GY25_UART: public GY25 {
public:
  void setup(HardwareSerial* serial = &Serial, int baud_rate=115200) {
	  GY25_UART::serial = serial;
    GY25_UART::serial.begin(baud_rate);
    GY25_UART::setupBasic();
  }
private:
  HardwareSerial* serial;
  int availableGyro() {
    return GY25_UART::serial.available();
  }
  int readGyro() {
    return GY25_UART::serial.read();
  }
  void writeGyro(int data) {
    GY25_UART::serial.write(data);
  }
};