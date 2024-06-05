#include <graphics.h>

int main() {
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Set circle parameters
    int x = getmaxx() / 2;  // Center at the middle of the screen
    int y = getmaxy() / 2;
    int radius = 150;       // Radius of 100 pixels

    // Draw the circle
    circle(x, y, radius);

    getch();  // Wait for a key press
    closegraph();  // Close graphics mode

    return 0;
}

