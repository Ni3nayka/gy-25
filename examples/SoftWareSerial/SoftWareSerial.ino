/*
   arduino library for gy-25 module:
   https://github.com/Ni3nayka/gy-25

   author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka
   write:  June 2024
   modify: August 2024
*/  

// подключаем библиотеку
#include <gy-25.h>

// объявляем объект для работы с гироскопом
GY25 gy25(8,7); // (TX,RX) - пины гироскопа

void setup() {
  // запускаем монитор порта
  Serial.begin(9600);
  // запускаем гироскоп
  gy25.setup(); // по умолчанию скорость 115200 "gy25.setup(115200)", если нужна 9600 то "gy25.setup(9600)"
  // калибруем гироскоп (как правило не нужно)
  // gy25.calibration();
}

void loop() {
  // обновляем гироскоп
  gy25.update();
  // вывести все данные с гироскопа в монитор порта
  gy25.print();
  // Запросить данные с гироскопа и вывести их в монитор порта
  Serial.print(gy25.angle[0]); // X
  Serial.print(" ");
  Serial.print(gy25.angle[1]); // Y
  Serial.print(" ");
  Serial.print(gy25.angle[2]); // Z
  Serial.print(" ");
  Serial.print(gy25.horizontal_angle); // абсолютный горизонтальный угол
  Serial.println();
}
