#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"
#include "Point2D.h"

class Square : public Rectangle {
public:
    Square();
    Square(std::string color, Point2D* vertices);

    void set_vertices(Point2D* vertices);
    void print() const override;

    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;

    friend std::ostream& operator<<(std::ostream& out, const Square& square);

private:
    static bool check(Point2D* vertices);
};

#endif


