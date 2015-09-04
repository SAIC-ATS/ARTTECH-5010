---
layout: page
title:  Syllabus
---

## Experimental Media, ATS 5010

Semester, Year
:   Fall, 2015

Meeting Times
:   Friday 1pm-4pm

Meeting Location
:   MacLean 426

Instructor
:   [Christopher Baker](http://christopherbaker.net)

--------------------------------------------------------------------------------

### Instructor Bio
[Christopher Baker](http://christopherbaker.net) is an artist whose work engages the rich collection of social, technological and ideological networks present in the urban landscape. He creates artifacts and situations that reveal and generate relationships within and between these networks.  Christopher’s work has been presented worldwide and he contributes to the open source community at [http://github.com/bakercp](http://github.com/bakercp).

--------------------------------------------------------------------------------

### Course Description
Experimental Media introduces graduate students to the basic strategies and techniques associated with using experimental media such as robotics, microcontrollers, networked objects, and basic interactivity.

### Course Goals
In concert with the Grad Digital Media Seminar, this course aims to equip new graduate students with foundational tools, techniques and technologies essential to a successful graduate career in Art and Technology Studies.  In addition to school fabrication resources, students will be introduced to a variety of contemporary techniques, practices and creative methodologies.

__Key goals include:__

- Working knowledge of contemporary creative coding tools, with intermediate skills in one or more
- Working knowledge of contemporary creative hardware tools, with intermediate skills in one or more
- Working knowledge of and hands-on exposure to the school’s various fabrication facilities
- Working knowledge of popular online resources for:
  - Materials
  - Electronics
  - Hardware
- Working knowledge of contemporary artists and groups addressing issues related to art and technology
- Working knowledge of intermediate linux/unix OS features (scripting, terminal, automation, etc)
- Building camaraderie between first year students and their classmates.

### Methodology
Using individual in-lab and home assignments, class presentations, lectures, discussions, assigned readings, group and individual desk critiques, students will experience multiple aspects of interactive design.  Visiting artists / faculty may enhance the experience and offer additional perspectives.

### Assignments
The course may include workshops and several small projects, relevant technical and theoretical reading, written online responses, technical research and outings.

### Recommended Texts

- [ofBook](https://github.com/openframeworks/ofBook)
- Getting Started with Arduino, Second Edition, By Massimo Banzi (aka GSA)
- Programming Interactivity, Second Edition By Josha Noble (aka PI)

_Note: Both O'Reilly books are available in DRM-free eBook form from [http://oreilly.com/](http://oreilly.com/).  Steep discounts are available: [http://www.google.com/?q=coupon+oreilly.com](http://www.google.com/?q=coupon+oreilly.com)._

### Reading and other Resources
Posted on the course website.

### Materials
Provided by the student as needed.

### Attendance
1. Students are best served by attending all classes.
2. Missing three classes will result in a class failure.  This is strictly enforced.
3. Six or more unexcused late arrivals or early departures will result in class failure.

_Tip: If you are going to be absent, late to class, or need to depart early, please contact me BEFORE class starts.  This is so I can make sure you have what you need to succeed!_

### Wait Lists  
Students wait-listed for classes will be admitted on a space available basis determined by instructors’ discretion (in consultation with the department chair).

### Grading Procedure/Criteria
Grades are credit / no-credit for this course. Credit for the course is given when _all_ assignments are completed.

### Writing Assistance
[Writing Center](http://www.saic.edu/webspaces/portal/advising/write\_center.html)

### Special Needs
[Disability and Learning Resource Center](http://www.saic.edu/lifeatsaic/wellnesscenter/disabilityandlearningresourcecenter/)

### Course Schedule

_(subject to change based on incoming skills and experience)_

#### Week 1
- Introduction to course
    - How does this fit in with other courses?  
    - History of course?
    - What does it mean for us?
- Introduction to each other
- Survey of Creative Coding Platforms
    - History
    - Contemporary Options w/ Examples
        - [openFrameworks](http://openframeworks.cc/) vs. [Processing](http://processing.org/) vs. [p5.js](http://p5js.org/) vs. [ProcessingJS](http://processingjs.org/)
        - [openFrameworks](http://openframeworks.cc/) vs. [Nodebox](http://nodebox.net/)
        - [openFrameworks](http://openframeworks.cc/) vs. [libCinder](http://libcinder.org/)
        - [MaxMSP/Jitter](http://cycling74.com/products/max/) vs. [VVVV](http://vvvv.org/) vs. [PD](http://puredata.info/) vs. [QuartzComposer](http://en.wikipedia.org/wiki/Quartz_Composer)
        - [Unity3D](http://unity3d.com/)
    - The future?
- Survey of Creative Hardware Hacking Platforms
    - History
    - Contemporary Options w/ Examples
        - [Arduino](https://www.sparkfun.com/categories/103?page=all) (in all of its forms, clones, etc)
        - [Teensy](https://www.sparkfun.com/categories/267)
        - Mobile phones and similar devices
        - Arm Devices
            - [Raspberry Pi](http://www.raspberrypi.org/)
                - [Banana Pi](http://www.bananapi.org/)
                - [ODROID-W](http://www.hardkernel.com/main/products/prdt_info.php?g_code=G140610189490)
                - [and on and on ...](http://www.pcworld.com/article/2599640/this-more-powerful-raspberry-pi-competitor-is-totally-free.html)
            - [Arduino Tre](http://arduino.cc/en/Main/ArduinoBoardTre)
            - [Beagle Bone Black](http://beagleboard.org/black)
            - [PCDuino](http://www.pcduino.com/)
            - [UDOO](http://www.udoo.org/)
        - The future?
- So what are we going to focus on?
    - Software
        - [openFrameworks](http://openframeworks.cc/) using [ofSketch](https://github.com/olab-io/ofSketch) (C/C++)
        - "Arduino" Language (C/C++)
    - Hardware
        - Desktop / Laptop
        - Arduino
        - Raspberry Pi

#### Week 2
- Introduction to the command line.
    - https://github.com/olab-io/microWorkshops/blob/master/Terminal_Intro/Terminal_Intro.md
- Introduction to git / github.
    - https://github.com/olab-io/microWorkshops/blob/master/Git_Intro/Git_Intro.md
    - https://github.com/openframeworks/ofBook/blob/master/chapters/version_control_with_git/chapter.md
- Introduction to the ofSketch IDE.
    - https://github.com/olab-io/
    - https://github.com/openframeworks/ofBook/blob/master/chapters/ofSketch/chapter.md

#### Week 3
- Bookkeeping
    - Why are we using `git` + `http://github.com`?  Google Docs or Canvas would be a lot easier.
    - How do I get help when I am not sure how to do something?
        - Google it / Search a forum.
        - Browse in your book.
        - Ask a human (your peers or me are a good first place to )
            - Ask you peers
            - Ask me
    - Assignments
        - Essential that you are tracking with the group.
        - Essential that you seek help from your peers or from me
- Introduction to Programming: _A comparative studio between Arduino + openFrameworks_
    - Anatomy of a Program
        - openFrameworks
        - Arduino
    - Anatomy of an Addon
        - openFrameworks
        - Arduino
    - Programming syntax, a comparative study
        - Basic Output (Part 1)
        - openFrameworks:
            - Drawing: shapes
        - Arduino:
            - Blinking!
            - Analog Input
            - Digital Input

#### Week 4
- Bookkeeping
    - Github / Terminal Questions
    - Ask for help!
    - Basic Serial Communication
        - What is serial communication?
        - What is 9600 baud?

#### Week 5
- Drawing, Animation and Graphics.

#### Week 6
- Bookkeeping
    - DIY Orientations
        - ATS Kinetics Lab Orientation/Authorization (go down during open access @ 4:15 ... be there @ the beginning!)
        - ATS I/O Lab Orientation/Authorization ()
        - CNC / Shop / Orientation [(http://www.artic.edu/webspaces/portal/irfm/shops.html]())
        - Advanced Output Center Orientation [http://crit.artic.edu/aoc/faq.php](http://crit.artic.edu/aoc/faq.php)
- Compiling: Under the hood
    - `*.h` + `*.cpp`
    - If Arduino is C++, why don't we have `*.h` / `*.cpp` files?
    - Preprocessor
        - An opportunity conditionally manipulate the text of your code BEFORE it is compiled.
        - What are _macros_?
        - What is a preprocessor variable?
        - Where do preprocessor variables come from?
        - Preprocessor variables / macros often look like `__APPLE_CC__`.
        - Important preprocessor variables
            - `#include`
            - `#pragma once` vs. `#ifndef FOO ...`
    - Compiler
        - The process of translating our C++ langauge instructions (code) into hardware-specific instructions (code).
        - Usually produces object (`*.o`) files, usually behind the scenes.
    - Linker
        - Fuses all of the compiled object files and libraries (including 3rd party libraries) into an executable application.
- Basic Output w/ Arduino (Part 2)
    - Looping, Timing, Repetition and Iteration in openFrameworks+Arduino
    - delays
    - interrupts vs. polling
    - `for` / `while` / `do` `while`
    - Basic Input and Behaviors
- openFrameworks:
    mouse,
    keyboard,
    switches from the Arduino

---

- Materials Roundup
    - e.g. [http://www.inventables.com/](http://www.inventables.com/) 


#### Week 7
- Object-Oriented-Programming (OOP) vs. ?
    - `ofDrawRectctangle` vs. `ofRectangle`
- What is a `class`? (what is a `struct`?)
    - What is a member variable?
    - What is a member function?
    - What is static data?
    - What are static member functions?
    - How do member functions differ from "global" functions?
    - How do static member functions differ from "global" functions?
    - Syntax
        - `.`
        - `::`
        - `virtual`
        - `const`
        - `mutable`
    - Member functions
        - rules vs. conventions
            - `draw()`, `update()`, etc.
    - Inheritance
        - `public`, `protected`, `private`
    - Review Collections
        - "Raw" arrays
            - Pointers (mention)
        - Memory management
            - `new` vs `delete`
    - Review functions / methods
        - Passing by value
        - Passing by reference
        - Passing by pointer
        - Returning by value
        - Returning by reference
        - Returning by pointer
        - What is "const"?

- Arduino: simple analog sensors: button, light sensors

- Variables in openFrameworks+Arduino:
    -   data types
    -   variables
    -   math
    -   mapping and scaling
    -   repetition
    -   randomness

#### Week 9

-   Advanced Programming Theory / Syntax

-   openFrameworks/Arduino

-   Functions
-   OOP (Object oriented programming), Classes, Objects
-   Arrays

#### Week 9

-   Intermediate I/O

-   openFrameworks:

-   Audio I/O
-   Video I/O
-   Hardware Serial (RS-232) (talking to the arduino)

-   Arduino:

-   Hardware Serial (RS-232) (talking to openFrameworks)
-   Intermediate sensors (gyro, accelerometer, GPS, capacitive touch,
    etc)
-   Audio/Video on the Arduino (Survey)

#### Week 10

-   Intermediate I/O (continued)

#### Week 11

-   Advanced I/O (Input/Output)
-   openFrameworks:

-   Live Network feeds (push and pull)
-   Data persistence (saving data and preferences)
-   Database interface (MySQL, sqLite, XML, PHP/Web)

-   Arduino:

-   Wired/Wireless Networking (hardware vs. USB proxy)
-   Software serial (RS-232) talking to other Arduinos
-   Advanced sensor/device communication SPI
-   Advance IC interfacing / Bitbanging (bitwise operators)

-

#### Week 13

-   Advanced Topics and Integration

-   - "The circle of life" agile digital fabrication and advanced output

-   scan, modify, print, repeat
-   Topics include:

-   advanced 2D output (vector/svg for laser cutter/CNC)
-   3D in openFrameworks (opengl)
-   advanced 3D output (DXF, Collada) for 3D printer

-   Creative 3D design with sensor data (arduino)

-   sensor data to 3D object

-   Introduction to 3D tools

-   Meshlab
-   Blender || Sketchup || Rhino

#### Week 14
-   Advanced Topics and Integration (continued)

#### Week 15

-   Advanced Topics and Integration (continued)
