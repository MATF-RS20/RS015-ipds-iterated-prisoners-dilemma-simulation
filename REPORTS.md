# Weekly project reports

## Week 1 (25.11.)

DONE:

- decided on the idea
- drafted UML
- tried working in Unreal, realized it was more realistic to make this in qt
- set up YouTrack with descriptions of features, sketches, timers, links, tasks, deadlines, etc.

NEXT WEEK PLAN:

- develop Specimen abstract class for specimen with different strategies to inherit
- develop the following strategies: Dove, Hawk, AllRandom, Pavlov, Tit-for-Tat, Two-Tits-for-Tat, Tat-for-Two-Tits
- develop the Simulation class which will house the logic for the whole simulation
- develop enums for strategies and outcomes
- start working on the layout of the graphical interface 

## Week 2 (2.12.)

DONE:

- developed Specimen
- developed all of the derived strategies
- developed the skeleton for the Simulation class
- implemented enums for strategies and outcomes
- decided on how the interface will look and which functionalities it will have
- made a basic window and started looking into how to use Widgets to implement the interface we wanted

NEXT WEEK PLAN:

- make assets for Specimen
- look into using a library to draw a graph of iteration histories
- start working on specimen encounter animations
- implement getters, setters, other methods, and supporting classes for Simulation
  - connect them to the interface so the user can edit simulation parameters
- implement Food and random assignment of Specimen to it
- limit reproduction by the amount of food (hard limit) 

## Week 3 (9.12.)