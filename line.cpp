#include <graphics.h>

int main() {
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Define line coordinates (x1, y1) and (x2, y2)
    int x1 = 150, y1 = 50;
    int x2 = 300, y2 = 250;

    // Draw the line
    line(x1, y1, x2, y2);

    getch();  // Wait for a key press
    closegraph();  // Close graphics mode

    return 0;
}


