SMotor
========================================

This is a library for stabilizing motor speed, using in the SRobot contest, 2018.

Required Additional Libraries
--------------------
* **[Arduino PID Library](https://github.com/br3ttb/Arduino-PID-Library/)**
* **[Encoder Library](https://github.com/PaulStoffregen/Encoder)**
* **[SimpleKalmanFilter](https://github.com/denyssene/SimpleKalmanFilter)**

Repository Contents
--------------------
* **/examples** - Example sketches for the library (.ino). Run these from the Arduino IDE.
* **/src** - Source files for the library (.cpp, .h).
* **keywords.txt** - Keywords from this library that will be highlighted in the Arduino IDE.

Basic Usage
--------------------
* Initialize a `Motor` object:
```c++
SMotor Motor(int INa, int INb, int EN, int A, int B);
```
* `IN1`, `IN2`, `ENABLE`: corresponding pins in module L298
* `A`, `B`: motor encoder pins

Functions:
* `stop()`: stop the motor
* `spin(bool direction, double speedSet)`: Spin in the forward (true) or backward (false) direction in the expected speed (RPM). This function implements PID and *shall be called in a loop*

Version History
--------------------
* v0.2 - 16/03/2018: Simplifying functions, adding electromagnetic brake functionality.
