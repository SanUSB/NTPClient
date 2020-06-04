# ESP32/ESP8266 Timers ans Real Time Clock (RTC) [![N|Solid](http://sanusb.blogspot.com.br/favicon.ico)](http://sanusb.org/)


In this teaching material, a brief review of timers and Real-time cloks/calenders (RTC) available for ESP32 and ESP8266 microcontroller families is proposed. With the exception of the internal RTC example, which is a peripheral available only in ESP32, all other didactic examples in the repository have been tested and work in both ESP32 and ESP8266, being a relevant feature for several real applications. 

To install the librarys, follow the steps: 
Download the repository https://github.com/SanUSB/NTPClient , Arduino IDE -> Sketch -> Include Library -> Add NTPClient-Master .zip Libraries. 

To use, Unzip the .zip folder and access the examples folder.


More details at https://youtu.be/vyq2sJE_DwM and [Tutorial in Portuguese](https://github.com/SanUSB/NTPClient/tree/master/miscellaneous/Tutorial.pdf).

This topic is very relevant in real practical projects. Generally, in IoT automatic processes, timers and/or Real-time clocks (RTC) are used for scheduled process tasks.


In this sense, according to github itself at https://help.github.com/pt/github/getting-started-with-github/fork-a-repo, this project https://github.com/SanUSB/NTPClient
was forked and modified to support the examples practical timers and RTCs available for both models. All examples can be repeated by anyone 
interested, with just a computer and an ESP microcontroller and no other peripherals, since even the LED used is the BUILTIN contained on the microcontroller 
board.

As for ESP microcontrollers timers, we can classify them as:

**a. Hardware:** [aTimerHardwareESP32](https://github.com/SanUSB/NTPClient/tree/master/examples/aTimerHardwareESP32) , 
[aTimerHardwareESP8266](https://github.com/SanUSB/NTPClient/tree/master/examples/aTimerHardwareESP8266).

They are real peripherals contained in the internal hardware of the microcontrollers

**b. Emulated by software:** [bTimerSoftwareTicker](https://github.com/SanUSB/NTPClient/tree/master/examples/bTimerSoftwareTicker).

They are timers emulated by the microcontroller processor. The Ticker library is based on timers emulated by software.


As for Real-time clocks (RTC) applied in IoT systems, we can classify them as:

**c. RTC Online:** [cNTP](https://github.com/SanUSB/NTPClient/tree/master/examples/cNTP) , 
[NTPClient](https://github.com/SanUSB/NTPClient/tree/master/examples/cNTPclient).

They are based on NTP (Network Time Protocol)
Brazil has the NTP.br project with the objective of offering conditions for Internet servers to be synchronized with Brazilian Legal Time. NTP public servants in Brazil from stratum 2 of NTP.br are: *a.ntp.br*, *b.ntp.br* and *c.ntp.br*.

They are powered by primary servers (stratum 1), which are also publicly accessible, including *a.st1.ntp.br*, *b.st1.ntp.br*, *c.st1.ntp.br* and *d.st1.ntp.br*. These, are synchronized with atomic clocks, which are the responsibility of the National Observatory.

**d. Offline RTC:**

**d.i.** Using real internal RTC, in the case of ESP32: [diInternalRTCesp32](https://github.com/SanUSB/NTPClient/tree/master/examples/diInternalRTCesp32).


**d.ii.** [diiSoftEmulated](https://github.com/SanUSB/NTPClient/tree/master/examples/diiSoftEmulated).

Emulated via software, for example, using the ticker library (functional). It is worth mentioning that since ESP8266 does not have an internal RTC, emulating an RTC via software can be a viable possibility, especially for systems that require a lot of accuracy and level of seconds, considering that this procedure was used in a project to control lab RFID access and it worked as expected. A test on the comparison of this system with the NTP is shown in the video https://youtu.be/vyq2sJE_DwM.


**d.iii.** Using real external RTC, such as DS1307.


**e. Hybrid RTC:** [eHybridNTPclientInternalRTC](https://github.com/SanUSB/NTPClient/tree/master/examples/eHybridNTPclientInternalRTC) , 
[eHybridNTPsoftEmulated](https://github.com/SanUSB/NTPClient/tree/master/examples/eHybridNTPsoftEmulated).


Which uses, for example, NTP to reference and / or update clocks in real time (RTC) offline. Below, a graph with a summary of the types 
suggested in this research:

![](https://github.com/SanUSB/NTPClient/blob/master/Images/Fig.png)

*Have fun!*
