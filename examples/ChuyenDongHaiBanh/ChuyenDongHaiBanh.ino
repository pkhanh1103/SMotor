/*
 * ChuyenDongHaiBanh
 * 
 * Cho robot di chuyển theo đường thẳng bằng cách quay cùng 
 * lúc hai bánh với cùng một tốc độ.
 *
 * Robot đi theo một hướng nhất định trong 2 giây, dừng
 * 0.5 giây, và đi theo hướng ngược lại trong 2 giây một cách
 * lặp lại.
 * 
 * P/S: Phần định nghĩa tùy thuộc vào cấu hình mỗi robot.
 */

#include <SMotor.h>

//Định nghĩa các chân của Motor1
#define IN1 22
#define IN2 23
#define EN1 5
#define A1 2
#define B1 30

//Định nghĩa các chân của Motor2
#define IN3 24
#define IN4 25
#define EN2 6
#define A2 3
#define B2 32

//Khởi tạo hai đối tượng motor
SMotor Motor1(IN1, IN2, EN1, A1, B1);
SMotor Motor2(IN3, IN4, EN2, A2, B2);

int speed; 

//Tạo hai biến lưu giá trị thời gian
unsigned long now;
unsigned long lastCheck;

void setup() 
{
  lastCheck = millis();
  speed = 250;
}

void loop() 
{ 
  //millis() là hàm trả về thời gian (milli giây)
  //kể từ lúc mạch Arduino bắt đầu chương trình
  now = millis();

  if(now - lastCheck < 2000)
  {
    Motor1.spin(true, speed);
    Motor2.spin(false, speed);
  }
  else if(now - lastCheck <= 2500)
  {
    Motor1.stop();
    Motor2.stop();
  }
  else if(now - lastCheck <= 4500)
  {
    Motor1.spin(false, speed);
    Motor2.spin(true, speed);
    lastCheck = now;
  }
}