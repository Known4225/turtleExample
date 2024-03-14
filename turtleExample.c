/* example of the turtle module */

#include "include/turtle.h"
#include <time.h>

int main(int argc, char *argv[]) {
    GLFWwindow* window;
    /* Initialize glfw */
    if (!glfwInit()) {
        return -1;
    }
    glfwWindowHint(GLFW_SAMPLES, 4); // MSAA (Anti-Aliasing) with 4 samples (must be done before window is created (?))

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(960, 720, "Drawing", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetWindowSizeLimits(window, GLFW_DONT_CARE, GLFW_DONT_CARE, 960, 720);

    /* initialize turtle */
    turtleInit(window, -240, -180, 240, 180);

    int tps = 60; // ticks per second (locked to fps in this case)
    clock_t start, end;
    turtlePenSize(10);
    /* this is the main loop
    All this program does is allow you to draw on the screen with the mouse
    Click and drag to draw lines on the canvas
    Press C to clear the canvas
    */
    while (turtle.close == 0) {
        start = clock();
        // printf("%d\n", turtle.penPos -> length);
        turtleGetMouseCoords(); // get the mouse coordinates
        turtleGoto(turtle.mouseX, turtle.mouseY);
        if (turtleMouseDown() && turtle.mouseX > -241 && turtle.mouseX < 241 && turtle.mouseY > -181 && turtle.mouseY < 181) {
            turtlePenDown();
        } else {
            turtlePenUp();
        }
        if (turtleKeyPressed(GLFW_KEY_C)) {
            turtleClear();
        }
        turtleUpdate(); // update the screen
        end = clock();
        while ((double) (end - start) / CLOCKS_PER_SEC < (1 / (double) tps)) {
            end = clock();
        }
    }

    // turtleMainLoop(); // stall the window

    glfwTerminate();
    return 0;
}