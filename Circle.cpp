#include "Circle.h"
#include <cmath>
#include <iostream>

const double PI = 3.141592;

using namespace std;

Circle::Circle() : Shape(), center(Point2D(0, 0)), radius(1) {}

Circle::Circle(string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}

Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    radius = r;
}

ostream& operator<<(ostream &out, const Circle &c) {
    out << "Centro: " << c.center << ", radio: " << c.radius << ", color: " << c.get_color();
    return out;
}

// Métodos heredados de Shape
double Circle::area() const {
    return PI * pow(radius, 2); 
}

double Circle::perimeter() const {
    return 2 * PI * radius; 
}

void Circle::translate(double incX, double incY) {
    center.set_x(center.get_x() + incX);
    center.set_y(center.get_y() + incY);
}

void Circle::print() const{
    cout << "Centro del círculo: " << center << ", radio: " << radius << ", color: " << get_color() << endl;
}

