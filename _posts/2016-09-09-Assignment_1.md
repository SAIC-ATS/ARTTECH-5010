---
layout:     assignment
categories: assignment
title:      Assignment 1
subtitle:   Finite State Machines
author:     bakercp
date:       2016-09-09 00:00:00
due:        2016-09-16
---

![The board](/ARTTECH-5010/images/2016-09-09-Assignment_1_board.jpg)


1. Analyze 3 or more of the following systems/behaviors using Finite State Machines.  
  - Your options are:
    1. A soda machine containing Orange Juice, Grape Juice, and Sparkling Water.  Attempt to model all of the normal vending behaviors of the machine, including a user purchasing a beverage, and a user attempting to purchase a sold-out-beverage.
    2. A ghost in pac-man.
    3. One of the belts in [Standards and Double Standards](http://www.lozano-hemmer.com/standards_and_double_standards.php)
    4. The dog in [Sniff](http://www.gravitytrap.com/artwork/sniff)
    5. The mind of a 2 year old.
    6. The mind of a graduate student.
    7. A CTA turn-stile.

2. For each system / behavior you choose above, determine the answers to these questions:
  1. What are the possible "states" of the system?
    - _(e.g. For a stop light, we might name the RED, YELLOW, and GREEN states)_
  2. What variables (sensor input, timers, etc) do we need to keep track of?
    - _(e.g. For a simple stop light, we just keep track of the last transition time)_.
  3. Given the states listed above, what are valid / legal pathways to other states?  Are all transition pathways possible?
    - _(e.g. For a simple stop light, we are permitted to transition from GREEN -> YELLOW, but we cannot transition from GREEN -> RED directly)_.
  4. For all of the valid transition pathways listed above, what are the  variable values required to make the transition?
    - _(e.g. For a simple stop light, we require a certain amount of time to pass before we move to the next state.)_.
  5. What actions must be taken when entering a state?
    - _(e.g. Change the state variable, record the transition time, and turn on the light, etc.)_
  6. What actions must be taken when leaving a state?
    - _(e.g. ... turn on the light.)_

3. Make a Finite State Machine diagram for each system you analyze.
4. Submit your diagrams to me via email and be prepared to present them in class.

4. Learn about "Git" and "Github"
  - Why? _Git is a tool that you'll use all the time in this class and in your future lives as Creative Coders. It's by far the most popular way to share and manage code and should become a bit like breathing as you develop code._
    - If you learn by **reading**, consider this: [Version Control with Git](http://openframeworks.cc/ofBook/chapters/version_control_with_git.html)
    - If you learn best by **watching videos**, check out [Up and Running with Git and GitHub](https://www.lynda.com/Git-tutorials/Up-Running-Git-GitHub/409275-2.html) (about 1.25 hours).
      - _Remember that you have "free" access to Lynda.com through SAIC. Go [here](http://www.saic.edu/academics/computing/lyndaonlinesoftwaretraining/) to log in._

5. Analog Input
    - Build and test the [Analog Input Example](https://www.arduino.cc/en/Tutorial/AnalogInput) with a potentiometer ("pot") and photo resistor.
    - Extend the example to include two potentiometers and two LEDs.
    - If you don't have the required components, you can get them at the media center. They are very cheap.
    - Read [this](https://learn.sparkfun.com/tutorials/analog-to-digital-conversion) for more tips.

6. Analog Output
    - Work through the [Analog Output Example](https://www.arduino.cc/en/Reference/AnalogWrite).

7. Questions?  Ask them on the class forum.