---
layout:     assignment
categories: assignment
title:      Assignment 4
subtitle:   ofIntro.
author:     bakercp
date:       2016-09-30 00:06:00
due:        2016-10-07
---


1. Building off of [this week's examples](https://github.com/SAIC-ATS/ARTTECH-5010/tree/master/Week_04).
  - Create a self-portrait using simple drawing functions.
    - Make your window 800 x 800 pixels.  (`ofSetWindowShape()` can be called in `setup()`).
    - Set your background color using `ofBackground()`.
    - Use simple drawing functions like `ofDrawRectangle`, `ofDrawEllipse`, `ofDrawCircle`, `ofLine`.
    - Use repetition (`for`-loops) to create patterns.
    - Use conditional statements (`if` statements) to make some portion of your self-portrait react to a mouse press and its position.  For example, you might make your eyes close if you click on them.
        - Use `ofGetMouseX()` and `ofGetMouseY()` to get the current mouse position.
        - Use `ofIsMousePressed()` to determine whether the mouse is pressed.\
    - Change colors by using `ofSetColor`.
    - You can enable or disable the filling of shapes with `ofFill()` and `ofNoFill()`.  Like color, this "state" will apply until you explicitly set it again.

3. Review Serial Communication
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
  - What are the difference between these four Arduino expressions?
      - `Serial.print("127");`, `Serial.print(127);`, `Serial.println(127);` and `Serial.write(127);`?
      - What are the advantages of using one over the others?
  - What is "ASCII" and why is it used?
  - If you are unsure of the answers any of those questions, look it up or check your notes.  If you are still are unclear post a question to the forum and we'll discuss it.

2. Key questions you are expected to be able to answer after the project above.
    - Arrays
        - What is the difference between an array and a `std::vector`?
    - Looping
        - What is the difference between a standard `for`-loop and a range-`for` and why might you use one vs. the other?
    - If you are unsure of the answers any of those questions, look it up or check your notes.  If you are still are unclear post a question to the forum and we'll discuss it.
