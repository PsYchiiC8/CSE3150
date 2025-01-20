#include "Shape.h"

// Shape class methods
Shape::Shape(const std::string &_name) : name(_name) {

}

Shape::~Shape() {}

void Shape::printDetails() const {
    std::cout << "Shape: " << name << std::endl;
}

// Circle class methods
Circle::Circle(const std::string &_name, double _radius) : {
    radius = _radius;
}

Circle::~Circle() {

}

double Circle::area() const {
    // TODO
    return (radius * radius * pi);
}

double Circle::perimeter() const {
    // TODO
    return (2 * radius * pi);
}

void Circle::printDetails() const {
    std::cout << "Circle: " << ??? << std::endl;
    std::cout << "Radius: " << ??? << std::endl;
    std::cout << "Area: " << ??? << std::endl;
    std::cout << "Perimeter: " << ??? << std::endl;
}

// Rectangle class methods
Rectangle::Rectangle(const std::string &_name, double _width, double _height) :

??? {
}

Rectangle::~Rectangle() {}

double Rectangle::area() const {
    // TODO
    return (width * height);
}

double Rectangle::perimeter() const {
    // TODO
    return (2 * (width + height));
}

void Rectangle::printDetails() const {
    std::cout << "Rectangle: " << ??? << std::endl;
    std::cout << "Width: " << ??? << std::endl;
    std::cout << "Height: " << ??? << std::endl;
    std::cout << "Area: " << ??? << std::endl;
    std::cout << "Perimeter: " << ??? << std::endl;
}
