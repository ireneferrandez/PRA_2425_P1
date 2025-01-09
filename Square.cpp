// Square.cpp

#include "Square.h"
#include <cmath>
#include <iostream>

using namespace std;

Square::Square() : Rectangle() {}

Square::Square(string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw invalid_argument("No conforman cuadrado valido");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw invalid_argument("No conforman cuadrado valido");
    }
    Rectangle::set_vertices(vertices);
}

void Square::print() const {
    cout << "Cuadrado con vertices: ";
    for (int i = 0; i < N_VERTICES; ++i) {
        cout << "(" << vs[i].get_x() << ", " << vs[i].get_y() << ") ";
    }
    cout << "y color " << get_color() << endl;
}

double Square::area() const {
    double side = Point2D::distance(vs[0], vs[1]);
    return side * side;
}

double Square::perimeter() const {
    double side = Point2D::distance(vs[0], vs[1]);
    return 4 * side;
}

void Square::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

bool Square::check(Point2D* vertices) {
    double side = Point2D::distance(vertices[0], vertices[1]);
    return Point2D::distance(vertices[1], vertices[2]) == side &&
           Point2D::distance(vertices[2], vertices[3]) == side &&
           Point2D::distance(vertices[3], vertices[0]) == side;
}

std::ostream& operator<<(std::ostream& out, const Square& square) {
    square.print();
    return out;
}

