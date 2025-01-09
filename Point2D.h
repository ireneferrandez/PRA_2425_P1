#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <cmath>

class Point2D {
public:
    double x, y;

    Point2D(double x = 0, double y = 0);

    double get_x() const;
    double get_y() const;

    void set_x(double new_x);
    void set_y(double new_y);

    static double distance(const Point2D &a, const Point2D &b);

    friend bool operator==(const Point2D &a, const Point2D &b);
    friend bool operator!=(const Point2D &a, const Point2D &b);
    friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};

#endif

