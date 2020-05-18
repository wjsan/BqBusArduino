<p align="center">
  <a href="https://binquantum.wordpress.com/2020/05/16/bqbus-protocol/" target="_blank">
    <img src="https://i.ytimg.com/vi/EyJjiy2n3Zc/hqdefault.jpg?sqp=-oaymwEZCPYBEIoBSFXyq4qpAwsIARUAAIhCGAFwAQ==&rs=AOn4CLDv3W4lTz5kJmcDFF81dBJ7OTIupw" alt="Druida IDE">
    <p align="center">Open source easy of use protocol<p>
  </a>
</p>

# BqBusArduino

BqBus is an extremely simple and intuitive open source communication protocol, whose objective is to allow data transmission between embedded devices and high-level computer systems, prioritizing performance and ease of implementation.

## Table of contents 

- [Features](#features)
- [Quickstart](#quickstart)
- [Example](#example)

## Features

* Versatile data exchange beetween devices
* Lite implementation
* Easy of use

## Quickstart

* Install library to arduino lib directory, and import him to your code

```C++
#include "BqBus.h"
```

* Create an BqBus Instance, with parameter size.

```C++
BqBus bqBus(size);
```

* On setup, initialize desired serial port, and set him to BqBus Bus property

```C++
  Serial.begin(9600);
  bqBus.setBus(Serial);
```

* On loop, make sure to always call the method 'communicationTask()' from your BqBus instance

```C++
bqBus.communicationTask();
```

* To write a value on a register use setReg(unsigned int address, int value) method.

```C++
bqbus.setReg(address, value);
```

* To read value from a register use GetReg(unsigned int address) method.

```C++
bqbus.getReg(address);
```

## Example

This example, reads register 0, and turn on/off buitin led using readed value.

```C++

#include "BqBus.h"
  
BqBus pcApp(1);      //Instance to share 1 register with pcApp application
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                               //Initialize serial port
  pcApp.setBus(Serial);                             //Set serial port used to communicate with pcApp application
  pinMode(LED_BUILTIN, OUTPUT);                     //Configure board default output to control on-board led
}
  
void loop() {
  // put your main code here, to run repeatedly:
  pcApp.communicationTask();                      //Performs communication betteen arduino and pcApp application
  int cbValue = pcApp.getReg(0);                  //Get value from register address 0 (check box)
  digitalWrite(LED_BUILTIN, cbValue);             //Write check box value on led
}

```

Execution:

<p align="center">
  <img src="https://binaryquantum.files.wordpress.com/2020/05/novo-projeto.gif?w=544">
</p>
