#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

// Base class
class Shape {
public:
    Shape(const std::string &_name);

    virtual ~Shape();

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual void printDetails() const;

protected:
    std::string name;
};

// Derived class Circle inheriting from Shape
class Circle : public Shape {
public:
    Circle(const std::string &_name, double _radius);

    ~Circle();

    double area() const override;

    double perimeter() const override;

    void printDetails() const override;

private:
    double radius;
    double pi = 3.14159;
};

// Derived class Rectangle inheriting from Shape
class Rectangle : public Shape {
public:
    Rectangle(const std::string &_name, double _width, double _height);

    ~Rectangle();

    double area() const override;

    double perimeter() const override;

    void printDetails() const override;

private:
    double width;
    double height;
};

#endif // SHAPE_H
