#include "Drawing.h"
#include <iostream>

using namespace std;

Drawing::Drawing() {}

Drawing::~Drawing() {
    for (Shape* shape : shapes) {
        delete shape;
    }
}

void Drawing::add_front(Shape* shape) {
    shapes.insert(shapes.begin(), shape);
}

void Drawing::add_back(Shape* shape) {
    shapes.push_back(shape);
}

void Drawing::print_all() {
    for (Shape* shape : shapes) {
        shape->print();
    }
}

double Drawing::get_area_all_circles() {
    double total_area = 0;
    for (Shape* shape : shapes) {
        Circle* circle = dynamic_cast<Circle*>(shape);
        if (circle) {
            total_area += circle->area();
        }
    }
    return total_area;
}

void Drawing::move_squares(double incX, double incY) {
    for (Shape* shape : shapes) {
        Square* square = dynamic_cast<Square*>(shape);
        if (square) {
            square->translate(incX, incY);
        }
    }
}

