#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
protected:
    Point2D* vs;

public:
    static const int N_VERTICES = 4;

    Rectangle();
    Rectangle(std::string color, Point2D* vertices);
    Rectangle(const Rectangle& r);
    ~Rectangle();

    // Métodos heredados de Shape
    virtual double area() const override;
    virtual double perimeter() const override;
    virtual void translate(double incX, double incY) override;
    virtual void print() const;

    Point2D get_vertex(int ind) const;
    Point2D operator[](int ind) const;
    void set_vertices(Point2D* vertices);
    Rectangle& operator=(const Rectangle& r);
    friend std::ostream& operator<<(std::ostream& out, const Rectangle& r);

    static bool check(Point2D* vertices);
};

#endif

