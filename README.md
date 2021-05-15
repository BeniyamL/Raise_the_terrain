# Raise the terrain

## Description

Raise the terrain is an application project which create an isometric projection of a grid and totate it using the right and left down arrow. It is an optional project of holberton school to provide an additional mark for student.It was developed using the SDL tools.

![Isometric projection of a grid](/grid1.png)

---
## General Reuirements

    * The OS of your choice
    * A README.md file, at the root of the folder of the project is mandatory
    * All your functions must be commented and respect the Betty style
    * Your functions should be maximum 60 lines long (one statement per line)
    * Your functions should be maximum 80 column long
    * No more than 5 functions per file
    * There is no forbidden function for this project. You are allowed to use any system call and/or standard library function.
    * You are allowed to use all the functions provided by SDL2

----
## Task 0: Isometric projection
   * Draw Isometric projection of a grid by accepting altitude input from user. An example of the altitude can be

---

120 60 40 60 20 -20 -80 -120
40 20 30 30 -10 -40 -90 -110
20 30 10 06 -6 -20 -26 -90
00 -6 10 10 -6 -20 -20 -40
-20 -20 -18 -14 -40 -20 -20 -30
-10 -10 -10 -10 -8 -20 -20 -30
20 10 10 10 10 04 10 -10
30 24 24 22 20 18 14 16

----

### Maths

 * To draw a grid using isometric projection, you’ll need to convert 3D coordinates (coordinates in the real world) to 2D coordinates (coordinates on the screen), as follows:

 * You can choose to incline your grid as much as you want.
---

WX = inclination * X - inclination * Y;
WY = (1 - inclination) * X + (1 - inclination) * Y - Z;

where an inclination of 70% would have a value of 0.7 in this above equation.

---

## specific Requirements

    * Usage: terrain file
    * Draw a grid using an isometric projection
    * The grid must be described in a file (see above example)
    * The color used to draw the grid doesn’t matter (same for the background)
    * The grid doesn’t need to be exactly the same as the one shown above. But make sure you have a coherent isometric projection.
    * Your grid must be centered and takes as much space as possible on the screen. We should be able to see the whole screen.
    * Your program should end when the user is pressing the ESC key


## Task 1. Rotation
    * Rotate the grid when the user is using left or right arrows
    * Please use the M_PI macro defined in math.h
    * Link with the gcc -m flag to be able to use the math library

### maths
    * The 2D point you want to rotate is defined with the coordinates [x, y].
    The rotation angle a is calculated as follow:

---

a = Angle * PI / 180

Angle being the angle in degrees, and a the angle in radians.

Rx = x * cos(a) - y * sin(a)
Ry = x * sin(a) + y * cos(a)

---

## How the project works
  
    * the project will accept the altitude from the user
    * It initializes the x and y coordinate to make the grid to be centered
    * It calculates the required space considering the dimension of the screen
    * It draw the the grid using the x,y values and the calculated space
    * It Converts this picture into isometric projection using the above formula
    * It Rotates the grid when left or right arrow is pressed
    * The system quiets when escap key pressed or when quit button clicked

---

---
## System Usage
    
    * Download the source file from the github.com into your local machine
    * navigate to the Raise_the_terrain folder
    * Compile all source code ending with .c extension using the following flage
---
  gcc *.c -lm $(sdl2-config --cflags --libs) -o grid, here grid is the name given to the executable file
----
    *  lanuch the executable file and input the altitude like 
---
./grid terrain   --> here gird is the name of the executable file and terrain is the name of the file which contains the altitude values
---
   
    * The system then displays the isometric projection of the grid using the altitude values as shown below
   ![isometric](/grid1.png)
    * press Right arrow key to rotate the isometric projection to the right
![rotated to the right](/grid4.png)
    * press Left arrow key to rotate the isometric projection to the left
![rotated to the left](/grid3.png)
    * press Escape key or quit button to exit the system

---

---
## Important Notes
   
   * the system displays 8 x 8 grid initialy, but you can change the dimentsion by updating the width and height value in header file
   * the system automatically displays the required space between rows and columns
   * you cal also adjust the screen width and height by changing the screen width and height value  in the header file

---
## Author
Beniyam Legesse (https://github.com/BeniyamL/)

