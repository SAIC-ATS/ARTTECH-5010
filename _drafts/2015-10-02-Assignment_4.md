---
layout:     assignment
categories: assignment
title:      Assignment 4
subtitle:   More Serial Communication
author:     bakercp
date:       2015-10-02 00:06:00
due:        2015-10-09
---


3. Required tutorials (for these, you may use Processing or Max/MSP or openFrameworks if you like).
    - [Debounce](https://www.arduino.cc/en/Tutorial/Debounce)
    - [ASCIITable](https://www.arduino.cc/en/Tutorial/ASCIITable)
    - [SerialCallResponse](https://www.arduino.cc/en/Tutorial/SerialCallResponse)
        - Note, you don't need force resistors for this example.  Simple buttons will suffice.
    - [SerialCallResponseASCII](https://www.arduino.cc/en/Tutorial/SerialCallResponseASCII)
        - Note, you don't need force resistors for this example.  Simple buttons will suffice.
    - [SerialEvent](https://www.arduino.cc/en/Tutorial/SerialEvent)




    3. Watch at least one of these videos [https://vimeo.com/eyeofestival/videos](https://vimeo.com/eyeofestival/videos).



    2. Read: ofBook [OOps!](http://openframeworks.cc/ofBook/chapters/OOPs!.html)
    . Extend the in-class light example that we started to include a pedestrian crossing signal that can be initiated by a button.
       	1. During normal operation (if the pedestrian cross button has not been pressed), the traffic light will function as it did in class.
      	2. When the pedestrian presses the button, the traffic will not stop immediately, but will complete its cycle and then signal the pedestrian that it is safe to cross (using the two additional LEDs), and then the system will return to its normal traffic light operation.
      	3. Before starting, modify the finite state machine diagram.  Identify and draw the additional states, transitions, and inputs associated with the pedestrian signal.
      	4. We will be discussing the problem here: [https://ats.community/t/assignment-1-the-traffic-light](https://ats.community/t/assignment-1-the-traffic-light) If you are unable to access that page contact me!
5
1. Make sure everything is complete from _Assignment 2_.
    - Please take time to review the Cylon Example.
    - Key questions you are expected to be able to answer after this week.
        - What is analog to digital conversion? (ADC)
            - How and when do you use it on an Arduino?
        - What is digital to analog conversion? (DAC)
            - How and when do you use it on an Arduino?
        - What is sampling frequency and why is it important to have a "fast" sampling frequency?
        - What are the SI units of frequency?
        - What is the difference between sampling frequency (`fs`) and sample resolution (aka bit depth)?
        - What is the formula for figuring out the number of "levels" that can be represented given a finite number of bits?
        - What is the sample resolution of a typical Arduino's 10 bit ADC?
        - What is the `AREF` pin for on an Arduino?
        - What is a "voltage divider" and how is it often used with the Arduino's analog input?
        - Draw a typical voltage divider circuit for hooking up an analog input (such as a photo cell) to an Arduino.
        - How does the Arduino simulate digital to analog output?
        - What is PWM and what is it used for?
        - What is a duty cycle?
        - How do PWM "frequency" and PWM "duty-cycle" differ?
        - What are pull-up and pull-down resistors and why are they needed?
        - Draw a typical pull-up and pull-down resistor circuit.
        - What is a typical values for a pull-down resistor when working with the digital input?
        - What is an array?  
        - Why might you use an array?
        - How do you access the elements inside an array?
        - How do you access the elements in an array using a `for-loop`?
        - Why might programmers call the first element in an array the zero-th rather than the "first"?
    - If you are unsure of the answers any of those questions, look it up or check your notes.  If you are still are unclear post a question to the forum and we'll discuss it.

1. Make sure everything is complete from _Assignment 3_.
    - Review Serial Communication
        - What is "serial" communication?
        - What is "parallel" communication?
        - What does it mean for serial communication to be asynchronous?
            - What is an example?
        - What does it mean for serial communication to be synchronous?
            - What is an example?
        - What does UART mean?
        - What are I2C and SPI and when are they used?
        - What is a "logic level" and what are common voltage values for logic levels?
        - Why do we have to specify the communication speed when using UART-style serial communication?
            - What are bauds?
            - What are data bits?
            - What are parity bits?
            - What are stop bits?
        - What is the difference between these two Arduino expressions?
            - `Serial.println(127);` and `Serial.write(127);`?
            - What are the advantages of using one over the other?
        - What is "ASCII" and why is it used?
    - If you are unsure of the answers any of those questions, look it up or check your notes.  If you are still are unclear post a question to the forum and we'll discuss it.

2. Serial Communication Reading Part 2
    - (optional)[SPI](https://learn.sparkfun.com/tutorials/serial-peripheral-interface-spi)
    - (optional)[I2C](https://learn.sparkfun.com/tutorials/i2c)

3. Using all that we have learned about the Arduino thus far, create your own project based upon your interests. This project is not required to use _everything_ we have covered but should demonstrate an attempt on your part to design a circuit and required code to create the effect that you want. This is _not_ meant to be a fully refined artistic concept (though you are welcome to give it as much polish as you would like!). It _is_ intended as an opportunity for you to apply and integrate what we have been working on in a way that makes sense for your practice. Think of it as a technological "study" for a future (or current) project.  Next week you are required to come with some significant progress completed. If you want to explore technologies that we have not yet covered in class (e.g. motors, sensors etc) next week will be an opportunity to work on some of those more specialized topics during class.  The following week, you will give a very brief (5-minute) review of your project, with special attention paid to the "new" techniques, technologies, and code that you discovered.
