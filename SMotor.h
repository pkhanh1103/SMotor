/* 
 * Thư viện SMotor - ổn định tốc độ motor của robot đa hướng trong SRobot 2018
 * Khởi tạo ngày 02/02/2018
 * Phiên bản: 0.2
 */

#ifndef SMotor_h
#define SMotor_h
#include "Arduino.h"
#include <PID_v1.h>
#include <Encoder.h>
#include <SimpleKalmanFilter.h>

class Motor
{
  public:
  
  Motor(int INa, int INb, int EN, int A, int B);   //Constructor - các tham số lần lượt là chân IN1, IN2,
                                                   //ENABLE của module L298; kênh A, kênh B của encoder

  void stop(void);                                 //Dừng motor
  
  void spin(bool direction, double speedSet);      //Quay motor theo chiều thuận (true) hay nghịch (false)
                                                   //theo tốc độ mong muốn(RPM - vòng/phút). Hàm này thực  
                                                   //hiện PID và nên được gọi trong một vòng lặp
  
  double speed;                                    //Tốc độ motor đo được theo đơn vị RPM

  private:

  /* ----- Motor ----- */
  int _INa;   //Chân IN1 của module L298 - điều khiển cực dương của motor
  int _INb;   //Chân IN1 của module L298 - điều khiển cực âm của motor
  int _EN;    //Chân ENABLE của module L298 - điều khiển tốc độ motor
  int _A;     //Kênh A của encoder gắn với motor
  int _B;     //Kênh B của encoder gắn với motor

  /* ----- PID ------ */
  int _sampleRate;         //Chu kì lấy mẫu tốc độ motor (mặc định: 10 milli giây)
  double _speedSet;        //Tốc độ motor mong muốn (RPM)
  double _pwm;             //Xung PWM ghi vào chân ENABLE của module L298
  
  unsigned long _now;          //Mốc thời gian hiện tại
  unsigned long _lastCheck;    //Mốc thời gian tại lần cuối tốc độ motor được đo
  long _oldPosition;           //Vị trí cũ mà encoder đo được
  long _newPosition;           //Vị trí mới mà encoder đo được

  void pidSet(double kp, double ki, double kd, int _sampleRate);  //Đặt tham số cho thuật toán PID
  
  /* ----- Các đối tượng tạo từ các thư viện ngoài ----- */
  Encoder myEnc;                  //Đối tượng đọc tín hiệu encoder
  SimpleKalmanFilter myFilter;    //Đối tượng lọc nhiễu tín hiệu encoder
  PID myPID;                      //Đối tượng điều khiển tốc độ motor
};

#endif