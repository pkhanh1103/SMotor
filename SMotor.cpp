/* 
 * Thư viện SMotor - ổn định tốc độ motor của robot đa hướng trong SRobot 2018
 * Khởi tạo ngày 02/02/2018
 * Phiên bản: 0.2
 */

#include "Arduino.h"
#include "SMotor.h"

SMotor::SMotor(int INa, int INb, int EN, int A, int B):
  myEnc(A, B),
  myPID(&speed, &_pwm, &_speedSet, 7.00, 10.00, 0.05, DIRECT),   //Đặt tham số PID
  myFilter(0.05, 0.05, 0.005) //Lọc nhiễu Kalman
{
  _INa = INa;   //Chân IN1 của module L298 - điều khiển cực dương của motor
  _INb = INb;   //Chân IN1 của module L298 - điều khiển cực âm của motor
  _EN = EN;     //Chân ENABLE của module L298 - điều khiển tốc độ motor
  _A = A;       //Kênh A của encoder gắn với motor
  _B = B;       //Kênh B của encoder gắn với motor

  //Setup các chân
  pinMode(_INa, OUTPUT);
  pinMode(_INb, OUTPUT);
  pinMode(_EN, OUTPUT);

  //Setup PID
  myPID.SetMode(AUTOMATIC);  //Khởi động PID
  
  //Reset thông số
  speed = 0;
  _pwm = 0;
  _speedSet = 0;
  _oldPosition = 0;
  _newPosition = 0;  
}

/*void Motor::pidSet(double kp, double ki, double kd, int _sampleRate)
{
  sampleRate = _sampleRate;
  myPID.SetTunings(kp, ki, kd);
  myPID.SetSampleTime(sampleRate);
  now = millis();
  lastCheck = millis();
}*/

void SMotor::spin(bool direction, double speedSet)
{
  _speedSet = speedSet;
  _now = millis();

  if (_speedSet == 0)
  {
    digitalWrite(_INa, 0);
    digitalWrite(_INb, 0);
    return;
  }
  if (direction == true)
  {
    digitalWrite(_INa, 1);
    digitalWrite(_INb, 0);  
  }
  else
  {
    digitalWrite(_INa, 0);
    digitalWrite(_INb, 1);
  }
  
  //Thực hiện PID sau mỗi chu kì lấy mẫu
  if (_now - _lastCheck >= _sampleRate)
  {
    _newPosition = myEnc.read();
    speed = abs(_newPosition - _oldPosition) * 60000 / 1734 / _sampleRate;
    speed = myFilter.updateEstimate(speed);
    _oldPosition = _newPosition;
    _lastCheck = _now;
  }

  myPID.Compute();
  analogWrite(_EN, _pwm);
}

void SMotor::stop(void)
{
  //Cung cấp đồng thời một mức điện áp vào hai cực của motor
  //tạo thành lực hãm điện từ, giảm ảnh hưởng của quán tính
  digitalWrite(_INa, 0);
  digitalWrite(_INb, 0);
}