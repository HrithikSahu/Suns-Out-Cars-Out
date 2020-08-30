# Suns-Out-Cars-Out
## Flashlight Controlled Solar Powered Robot using Arduino
This project is a light gradient sensitive robot with solar charging capabilities, in other words it seeks out the light to charge itself. It accomplishes this behavior with a set of four light sensitive photoresistors in voltage divider circuits, the  Arduino unit reads the four values which correspond to the intensity of the light received by the sensors through its analog read pins. It then applies a high voltage across a reed switch which completes a circuit between a 9v battery, and two toy motors, resulting in turning or moving towards the light. These motors were not able to be activated directly with the Arduino, if you get small enough motors, the switching portion of this project may be omitted without loss of functionality.If any of the four photodiodes is registering much higher than the others, it detects which photodiode is receiving the heightened signal and turns or moves in that direction for as long as the heightened signal is being received. This light tracking algorithm can be used to program solar panels to track on the sun, or for control of robot via flashlight, as is demonstrated here.

![Showcase](https://engineersgarag.wpengine.com/wp-content/uploads/2019/07/Prototype-Arduino-Based-Solar-Powered-Light-Controlled-Robotic-Tank.jpg)
