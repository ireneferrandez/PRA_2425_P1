#ifndef DRAWING_H
#define DRAWING_H

#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include <vector>
#include <iostream>

class Drawing {
private:
    std::vector<Shape*> shapes;

public:
    Drawing();
    ~Drawing();
    void add_front(Shape* shape);
    void add_back(Shape* shape);
    void print_all();
    double get_area_all_circles();
    void move_squares(double incX, double incY);
};

#endif



