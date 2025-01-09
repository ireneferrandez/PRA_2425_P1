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
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() const override{
        std::cout << "Rectangulo: color: " << color << std::endl;
        for (int i = 0; i < N_VERTICES; ++i) {
            std::cout << "Vertice " << i + 1 << ": (" << vs[i].get_x() << ", " << vs[i].get_y() << ")" << std::endl;
        }
    }

    Point2D get_vertex(int ind) const;
    Point2D operator[](int ind) const;
    virtual void set_vertices(Point2D* vertices);
    Rectangle& operator=(const Rectangle& r);
    friend std::ostream& operator<<(std::ostream& out, const Rectangle& r);

private:
    static bool check(Point2D* vertices);
};

#endif

