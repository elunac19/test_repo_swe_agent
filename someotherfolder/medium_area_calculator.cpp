#include <iostream>

double areaRectangle(double width, double height) {
    return width * height;
}

double areaCircle(double radius) {
    return 3.14159 * radius * radius;
}

int main() {
    std::cout << "Rectangle area: " << areaRectangle(4, 5) << std::endl;
    std::cout << "Circle area: " << areaCircle(3) << std::endl;
    return 0;
}
