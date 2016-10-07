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

2. Key questions you are expected to be able to answer after the project above.
    - Arrays
        - What is the difference between an array and a `std::vector`?
    - Looping
        - What is the difference between a standard `for`-loop and a range-`for` and why might you use one vs. the other?
    - If you are unsure of the answers any of those questions, look it up or check your notes.  If you are still are unclear post a question to the forum and we'll discuss it.
