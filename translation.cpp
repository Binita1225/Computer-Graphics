#include <iostream>
#include <graphics.h>

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Declare variables for starting and ending points, and translation distances
    int X1, Y1, X2, Y2, tx, ty;

    // Prompt user for input
    std::cout << "Enter starting points (X1, Y1): ";
    std::cin >> X1 >> Y1;
    std::cout << "Enter ending points (X2, Y2): ";
    std::cin >> X2 >> Y2;
    std::cout << "Enter translation distance (tx, ty): ";
    std::cin >> tx >> ty;

    // Translate starting and ending points
    X1 += tx;
    Y1 += ty;
    X2 += tx;
    Y2 += ty;

    // Draw the original line
    line(X1, Y1, X2, Y2);

    // Close graphics window
    delay(300000); // Delay to display the graphics
    closegraph();

    return 0;
}


