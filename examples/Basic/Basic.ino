/*
 * Basic
 * 
 * Cho quay motor 1 theo chiều thuận với tốc độ cho trước (đơn vị: vòng/phút).
 * 
 * P/S: Phần định nghĩa tùy thuộc vào cấu hình mỗi robot.
 */

#include <SMotor.h>

//Định nghĩa các chân của motor
#define IN1 22
#define IN2 23
#define EN1 5
#define A1 2
#define B1 30

//Khởi tạo đối tượng myMotor
SMotor myMotor(IN1, IN2, EN1, A1, B1);
int speed;

void setup() 
{
  speed = 250;
}

void loop() 
{ 
  myMotor.spin(true, speed);
}