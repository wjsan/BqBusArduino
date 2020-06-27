/**
 * @file LedBuiltInControl.ino
 * @author Wesley José Santos (https://binary-quantum.com)
 * @brief Arduino code example to work with LedBuiltInCotrol.exe
 * Repo of visual studio application: https://github.com/WesleyJoseSantos/BqBusNet
 * @version 0.1
 * @date 2020-05-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "BqBusSerial.h"

BqBusSerial pcApp(1);      //Instance to share 1 register with pcApp application

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                               //Initialize serial port
  pcApp.setBus(&Serial);                            //Set serial port used to communicate with pcApp application
  pinMode(LED_BUILTIN, OUTPUT);                     //Configure board default output to control on-board led
}

void loop() {
  // put your main code here, to run repeatedly:
  pcApp.communicationTask();                      //Performs communication betteen arduino and pcApp application
  int cbValue = pcApp.getReg(0);                  //Get value from register address 0 (check box)
  digitalWrite(LED_BUILTIN, cbValue);             //Write check box value on led
}