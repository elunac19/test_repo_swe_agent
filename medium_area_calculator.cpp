#include <iostream>
#include <cmath> // For M_PI, a more precise value of pi

// Abstract base class 'Shape'
class Shape {
public:
    // Pure virtual function for calculating area
    virtual double area() const = 0;
    // Virtual destructor (important for base classes with virtual functions)
    virtual ~Shape() {}
};

// ---

// Derived class 'Rectangle'
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Constructor
    Rectangle(double w, double h) : width(w), height(h) {}

    // Override the area method
    double area() const override {
        return width * height;
    }
};

// ---

// Derived class 'Circle'
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor
    Circle(double r) : radius(r) {}

    // Override the area method
    double area() const override {
        // Using M_PI from <cmath> for better precision if available,
        // otherwise, fallback to a defined constant.
        #ifndef M_PI
        #define M_PI 3.14159265358979323846
        #endif
        return M_PI * radius * radius;
    }
};