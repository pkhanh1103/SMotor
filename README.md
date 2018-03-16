SMotor
========================================

Đây là thư viện giúp ổn định tốc độ motor của robot đa hướng trong SRobot 2018.

Các thư viện bổ trợ (bắt buộc)
--------------------
Để thư viện này có thể hoạt động, cài đặt thêm các thư viện sau:
* **[Thư viện PID](http://playground.arduino.cc/Code/PIDLibrary)** của Brett Beauregard
* **[Thư viện Encoder](https://www.pjrc.com/teensy/td_libs_Encoder.html)** của Teensy
* **[Thư viện SimpleKalmanFilter](https://github.com/denyssene/SimpleKalmanFilter)** của denyssene

Các phần của thư viện
--------------------
* **/examples** - Các sketch mẫu của thư viện (.ino). Mở các file này từ Arduino IDE.
* **/src** - Mã nguồn thư viện (.cpp, .h).
* **keywords.txt** Các keyword của thư viện được highlight trong Arduino IDE.
* **extra_library_backup**- Các thư viện bổ trợ dự phòng, trong trường hợp các liên kết trên không còn khả dụng.


Hướng dẫn sử dụng cơ bản
--------------------
* Khởi tạo một đối tượng (object) motor:
```c++
SMotor Motor(int INa, int INb, int EN, int A, int B);
```
Trong đó: các tham số lần lượt là chân IN1, IN2, ENABLE của module L298; kênh A, kênh B của encoder
* Hàm stop(): dừng motor
* Hàm spin(bool direction, double speedSet): Quay motor theo chiều thuận (true) hay nghịch (false) theo tốc độ mong muốn (RPM - vòng/phút). Hàm này thực hiện PID và nên được gọi trong một vòng lặp

Tài liệu tham khảo
--------------------
**[Installing Additional Arduino Libraries](https://www.arduino.cc/en/Guide/Libraries)** - Cách cài đặt một thư viện Arduino

Lịch sử các phiên bản
--------------------
* V 0.2 - 16/03/2018: Đơn giản hóa các hàm, thêm tính năng hãm điện từ cho motor
* V 0.1 - 02/02/2018: Khởi tạo thư viện

Liên hệ
--------------------
Email: pkhanh1103@outlook.com