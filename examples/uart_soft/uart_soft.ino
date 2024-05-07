/*
   arduino library for gy-25 module:
   https://github.com/Ni3nayka/gy-25

   author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka
   write:  May 2024
   modify: May 2024
*/  

// подключаем библиотеку
#include <gy-25_uartSoft.h>

GY25 gy25(A0, A1); // RX, TX

void setup() {
  Serial.begin(9600);
  gy25.setup();
}

void loop () {
  gy25.update();
  gy25.print();
  delay(100);
}
