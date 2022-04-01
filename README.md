# Smart-Home-Project
Configuring ESP32 Microcontrollers on the M5 product line to automate the lights in my room and implement energy saving features. 

![image](https://user-images.githubusercontent.com/95356845/161324840-60ee21fb-1f01-4a39-abb9-52981a728985.png)

To do: 
  * Figure out what service to use to set up devices and have them speak with eachother. (Node-Red? Amazon Web Services?)
  * 3D model a housing unit for lightswitch Servo
  * Determine which Servo angle measurements are needed to adequately turn light switch. 
  * Figure out the positioning of the servo, and the start angle. 
  * Using the "Main Smart Room Controller" device, set up audio level measurements to decide that it should close my lights after 5 minutes of silence. 
  * Figure out how to make the main smart room controller device power off my stationary home PC after 15 minutes of silence. (Make sure you can toggle this off so it doesn't stop overnight downloads) 
  * Write C / C++ code to program the ESP32 microcontrollers with the logic to do all of this. 