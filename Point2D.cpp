#include <ostream>
#include <cmath>
#include "Point2D.h"

Point2D::Point2D(double x, double y) : x(x), y(y) {}

double Point2D::get_x() const {
    return x;
}

double Point2D::get_y() const {
    return y;
}

void Point2D::set_x(double new_x) {
    x = new_x;
}

void Point2D::set_y(double new_y) {
    y = new_y;
}

double Point2D::distance(const Point2D &a, const Point2D &b) {
    return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
}

bool operator==(const Point2D &a, const Point2D &b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Point2D &a, const Point2D &b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

