#include <iostream>
#include <graphics.h>

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Prompt user for input
    int numVertices;
    std::cout << "Enter the number of vertices of the polygon: ";
    std::cin >> numVertices;

    // Array to store original and scaled polygon coordinates
    int xCoords[numVertices], yCoords[numVertices];
    int xCoordsScaled[numVertices], yCoordsScaled[numVertices];

    // Input coordinates of each vertex
    std::cout << "Enter the coordinates of each vertex (x, y):" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i + 1 << ": ";
        std::cin >> xCoords[i] >> yCoords[i];
    }

    // Display original polygon
    setcolor(YELLOW);
    for (int i = 0; i < numVertices - 1; ++i) {
        line(xCoords[i], yCoords[i], xCoords[i + 1], yCoords[i + 1]);
    }
    line(xCoords[numVertices - 1], yCoords[numVertices - 1], xCoords[0], yCoords[0]);

    // Scaling factors for x and y axes
    double scaleX, scaleY;
    std::cout << "Enter the scaling factor for x-axis: ";
    std::cin >> scaleX;
    std::cout << "Enter the scaling factor for y-axis: ";
    std::cin >> scaleY;

    // Apply scaling to each vertex of the polygon
    for (int i = 0; i < numVertices; ++i) {
        xCoordsScaled[i] = static_cast<int>(xCoords[i] * scaleX);
        yCoordsScaled[i] = static_cast<int>(yCoords[i] * scaleY);
    }

    // Display scaled polygon
    setcolor(WHITE);
    for (int i = 0; i < numVertices - 1; ++i) {
        line(xCoordsScaled[i], yCoordsScaled[i], xCoordsScaled[i + 1], yCoordsScaled[i + 1]);
    }
    line(xCoordsScaled[numVertices - 1], yCoordsScaled[numVertices - 1], xCoordsScaled[0], yCoordsScaled[0]);

    // Wait for user input before closing the window
    delay(500000);
    closegraph();

    return 0;
}


