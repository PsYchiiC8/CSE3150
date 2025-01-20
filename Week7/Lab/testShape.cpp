#include "Shape.h"

#include <iostream>

int main() {
    // Create a Circle object
    Circle circle("MyCircle", 5.0);

    // Print details of the circle
    circle.printDetails();
    std::cout << std::endl;

    // Create a Rectangle object
    Rectangle rectangle("MyRectangle", 4.0, 3.0);

    // Print details of the rectangle
    rectangle.printDetails();
    std::cout << std::endl;

    // Polymorphism example: store shapes in an array
    Shape *shapes[2] = {&circle, &rectangle};

    // Print details of all shapes using the base class pointer
    for (int i = 0; i < 2; ++i) {
        shapes[i]->printDetails();
        std::cout << std::endl;
    }

    return 0;
}
