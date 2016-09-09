---
layout:     assignment
categories: assignment
title:      Assignment 2
subtitle:   Digital Representation
author:     bakercp
date:       2015-09-18 00:00:00
due:        2015-09-25
---

1. Make sure everything is complete from _Assignment 1_.
    - Please take time to review the Traffic Light Example.
    - Key questions you are expected to be able to answer after the Traffic Light project.
        - Variables
            - What is a variable and how do you _declare_ them in C++?
            - What is a variable's _scope_ and what is the difference between a _global_ scope and a _local_ scope?
            - Why might you declare a variable as read-only using the `const` keyword?
            - What are the differences between `long`, `int`, `float` and `bool` and when would you choose one over another?
        - Functions
            - What are _functions_ and how do you _declare_ them in C++?
            - Why would you use a function?
            - What does `void` mean in the context of a function declaration?
            - How is the `return` keyword used and in general what does it mean to _return_ from a function?
        - Program Flow
            - What does Arduino's `setup()` function do?
            - What does Arduino's `loop()` function do?
            - Why might it be important to avoid the `delay()` function?
        - Control
            - What is an `if` / `else` statement?
            - What is an `if` / `else if` / `else` statment?
        - Timing
            - What is the `millis()` function and how does it work?
            - What is the `micros()` function and how does it work?
        - Finite State Machine
            - When might it be useful to use a finite state machine (FSM)?
            - What are _states_ and how do they relate to _outputs_?
            - What are _events_ and how do they relate to _inputs_?
        - Input / Output
            - What are the steps for declaring and initializing an input pin?
            - What are the steps for declaring and initializing an output pin?
            - What are the purposes of `digitalRead()`, `digitalWrite()`, and `pinMode()`?
    - If you are unsure of the answers any of those questions, look it up or check your notes.  If you are still are unclear post a question to the forum and we'll discuss it.

2. Review Binary Representation
    - Watch: [Things - Counting in Binary on your Fingers](https://www.youtube.com/watch?v=apCLHmPsC68)
    - Remember: There are 10 kinds of people in the world.  Those who understand binary and those who don't.

3. Watch at least one of these videos [https://vimeo.com/eyeofestival/videos](https://vimeo.com/eyeofestival/videos).



2. Read: ofBook [OOps!](http://openframeworks.cc/ofBook/chapters/OOPs!.html)
. Extend the in-class light example that we started to include a pedestrian crossing signal that can be initiated by a button.
   	1. During normal operation (if the pedestrian cross button has not been pressed), the traffic light will function as it did in class.
  	2. When the pedestrian presses the button, the traffic will not stop immediately, but will complete its cycle and then signal the pedestrian that it is safe to cross (using the two additional LEDs), and then the system will return to its normal traffic light operation.
  	3. Before starting, modify the finite state machine diagram.  Identify and draw the additional states, transitions, and inputs associated with the pedestrian signal.
  	4. We will be discussing the problem here: [https://ats.community/t/assignment-1-the-traffic-light](https://ats.community/t/assignment-1-the-traffic-light) If you are unable to access that page contact me!