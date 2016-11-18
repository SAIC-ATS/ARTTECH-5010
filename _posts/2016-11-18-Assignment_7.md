---
layout:     assignment
categories: assignment
title:      Assignment 8
subtitle:   LEDs.
author:     bakercp
date:       2016-11-18 00:06:00
due:        2016-12-02
---


<iframe src="https://player.vimeo.com/video/184083332" width="640" height="1120" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>

_Enjoying more [AI Music](http://www.theverge.com/2016/6/1/11829678/google-magenta-melody-art-generative-artificial-intelligence) from Google?_

1. Please refer to assignment 2 for this week.  Instead of re-writing a completely new set of assignments, please adapt your code from assignment 2 to produce the same patterns with your NeoPixel strip.  If you don't have the exact number of LEDs, then you must determine how to make sure the unused LEDs are turned off.

2. LED Strip Notes
  - [Hardware Setup](https://learn.adafruit.com/adafruit-neopixel-uberguide/overview)
    - Please review the tips / tricks if you are trying to hook up a lot of LEDs.
  - Drivers
    - Any Arduino / Microcontroller
      - The more LEDs you attempt to control, the more current you will need from your power supply and the faster your microcontroller will need to be to service all of the the pixels fast enough.
    - [Fadecandy](https://github.com/scanlime/fadecandy) is a dedicated, sophisticated solution for lots of pixels.
      - This is often used with the [Open Pixel Control](http://openpixelcontrol.org/) Protocol
  - Software
    - Arduino Libraries
      - [Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) _We used this in class._
      - [FastLED](https://github.com/FastLED/FastLED) _Another popular option._
