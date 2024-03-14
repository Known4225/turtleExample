# Turtle Example

### Compile (windows 64 bit):
gcc turtleExample.c -L./Windows -lglfw3 -lopengl32 -lgdi32 -lglad -lole32 -luuid -DOS_WINDOWS -o turtleExample.exe\
Then run turtleExample.exe\
I've also included the 64-bit binary (turtleExample.exe) for convenience,\
so you can just run that without compilation if you're on windows (and on a 64 bit machine)

### Compile (linux):
gcc turtleExample.c -L./Linux -lglfw3 -ldl -lm -lX11 -lglad -lGL -lGLU -lpthread -DOS_LINUX -o turtleExample.o\
Then run ./turtleExample.o

### This example
This is a simple canvas example\
Click and drag with the mouse to draw lines on the canvas\
Press C to clear the canvas\
The window is set up for 4:3 aspect ration with coordinates from -240 to 240 on the x and -180 to 180 on the y, just like scratch\

### Turtle Commands

turtleGetMouseCoordinates() - puts the mouse coordinates in turtle.mouseX and turtle.mouseY variables, recommended to do at the beginning of your loop\
turtleGoto() - go to coordinates\
turtlePenDown() - start drawing\
turtlePenUp() - stop drawing\
turtleMouseDown() - returns 1 if the mouse is being held and 0 otherwise\
turtleKeyPressed(GLFW_KEY_X) - returns 1 if the key specified by GLFW_KEY_{KEY} is being held down and 0 otherwise\
turtleUpdate() - essential function to call at the end of your loop to update the screen with any changes that you made to it with turtle.

That should be it!