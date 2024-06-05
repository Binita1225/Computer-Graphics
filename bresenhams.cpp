#include <graphics.h>
#include <iostream>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;

    // Determine the increment for x and y
    int xInc = (x2 > x1) ? 1 : -1;
    int yInc = (y2 > y1) ? 1 : -1;

    int p = 2 * dy - dx;

    x = x1;
    y = y1;

    while (x != x2) {
        // Plot the current point
        putpixel(x, y, WHITE);

        if (p >= 0) {
            y += yInc;
            p -= 2 * dx;
        }

        x += xInc;
        p += 2 * dy;
    }

    // Plot the last point
    putpixel(x, y, WHITE);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;

    // Input the end points of the line
    std::cout << "Enter the coordinates of the first point (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Enter the coordinates of the second point (x2 y2): ";
    std::cin >> x2 >> y2;

    // Draw the line using Bresenham's algorithm
    drawLineBresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

