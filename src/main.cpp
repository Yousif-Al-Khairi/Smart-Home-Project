#include <Arduino.h>
#include <ESP32Servo.h>


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {

  myservo.attach(23);  // attaches the servo on pin 13 to the servo object
}

void loop() {
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}


/* 
Traceback (most recent call last):
  File "C:\Users\yousi\.platformio\packages\tool-esptoolpy\esptool.py", line 4582, in <module>
    _main()
  File "C:\Users\yousi\.platformio\packages\tool-esptoolpy\esptool.py", line 4575, in _main
    main()
  File "C:\Users\yousi\.platformio\packages\tool-esptoolpy\esptool.py", line 4074, in main
    esp = esp or get_default_connected_device(ser_list, port=args.port, connect_attempts=args.connect_attempts,
  File "C:\Users\yousi\.platformio\packages\tool-esptoolpy\esptool.py", line 120, in get_default_connected_device
    _esp = chip_class(each_port, initial_baud, trace)
  File "C:\Users\yousi\.platformio\packages\tool-esptoolpy\esptool.py", line 313, in __init__
    self._port = serial.serial_for_url(port)
  File "C:\Users\yousi\.platformio\penv\lib\site-packages\serial\__init__.py", line 90, in serial_for_url
    instance.open()
  File "C:\Users\yousi\.platformio\penv\lib\site-packages\serial\serialwin32.py", line 64, in open
    raise SerialException("could not open port {!r}: {!r}".format(self.portstr, ctypes.WinError()))
serial.serialutil.SerialException: could not open port 'COM11': PermissionError(13, 'Access is denied.', None, 5)
*** [upload] Error 1 */