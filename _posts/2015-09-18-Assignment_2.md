---
layout:     assignment
categories: assignment
title:      Assignment 2
subtitle:   Digital Representation
author:     bakercp
date:       2016-09-16 00:00:00
due:        2015-09-23
---

1. Build a simulation of a single traffic light with a cross-walk button (red, yellow, green for the traffic light, and perhaps white, red for the cross walk signal).  There should be one button that, in its turn, allows pedestrians to cross the street.  Steps to complete:
    1. Create a FSM diagram for the traffic light alone.  It should simply cycle through the colors appropriately.  Use the steps outlined in last week's assignment.
    2. Build the circuit, write some code and test it.
    3. Augment your FSM diagram to include the cross-walk behavior.
    4. Build the circuit, write some code and test it.

2. Make sure everything is complete from _Assignment 1_.
    - Key questions you are expected to be able to answer after the Traffic Light project above.
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
