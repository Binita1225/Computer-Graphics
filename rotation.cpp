#include <iostream>
#include <graphics.h>
#include <cmath>

#define PI 3.14159265

// Function to rotate a point (x, y) by angle theta around the origin
void rotatePoint(int& x, int& y, double theta) {
    double rad = theta * PI / 180.0;
    int newX = round(x * cos(rad) - y * sin(rad));
    int newY = round(x * sin(rad) + y * cos(rad));
    x = newX;
    y = newY;
}

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Prompt user for input
    int numVertices;
    std::cout << "Enter the number of vertices of the polygon: ";
    std::cin >> numVertices;

    // Array to store original and rotated polygon coordinates
    int xCoords[numVertices], yCoords[numVertices];
    int xCoordsRotated[numVertices], yCoordsRotated[numVertices];

    // Input coordinates of each vertex
    std::cout << "Enter the coordinates of each vertex (x, y):" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i + 1 << ": ";
        std::cin >> xCoords[i] >> yCoords[i];
        xCoordsRotated[i] = xCoords[i]; // Copy original coordinates for rotation
        yCoordsRotated[i] = yCoords[i];
    }

    // Display original polygon
    setcolor(YELLOW);
    for (int i = 0; i < numVertices - 1; ++i) {
        line(xCoords[i], yCoords[i], xCoords[i + 1], yCoords[i + 1]);
    }
    line(xCoords[numVertices - 1], yCoords[numVertices - 1], xCoords[0], yCoords[0]);

    // Angle of rotation in degrees
    double angle;
    std::cout << "Enter the angle of rotation (in degrees): ";
    std::cin >> angle;

    // Convert angle to negative for clockwise rotation
    angle = -angle;

    // Apply rotation to each vertex of the polygon
    for (int i = 0; i < numVertices; ++i) {
        rotatePoint(xCoordsRotated[i], yCoordsRotated[i], angle);
    }

    // Display rotated polygon
    setcolor(WHITE);
    for (int i = 0; i < numVertices - 1; ++i) {
        line(xCoordsRotated[i], yCoordsRotated[i], xCoordsRotated[i + 1], yCoordsRotated[i + 1]);
    }
    line(xCoordsRotated[numVertices - 1], yCoordsRotated[numVertices - 1], xCoordsRotated[0], yCoordsRotated[0]);

    // Wait for user input before closing the window
    delay(500000);
    closegraph();

    return 0;
}


