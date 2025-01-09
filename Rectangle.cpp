#include "Rectangle.h"
#include <iostream>
#include <cmath>

using namespace std;

Rectangle::Rectangle() : Shape(), vs(new Point2D[N_VERTICES]) {
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color), vs(new Point2D[N_VERTICES]) {
    if (!check(vertices)) {
        throw std::invalid_argument("No conforman un rectángulo valido.");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

Rectangle::Rectangle(const Rectangle& r) : Shape(r.get_color()), vs(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle() {
    delete[] vs;
}

bool Rectangle::check(Point2D* vertices) {
    double dist01 = Point2D::distance(vertices[0], vertices[1]);
    double dist23 = Point2D::distance(vertices[2], vertices[3]);
    double dist12 = Point2D::distance(vertices[1], vertices[2]);
    double dist30 = Point2D::distance(vertices[3], vertices[0]);

    return dist01 == dist23 && dist12 == dist30;
}

double Rectangle::area() const {
    double length = Point2D::distance(vs[0], vs[1]);
    double width = Point2D::distance(vs[1], vs[2]);
    return length * width;
}

double Rectangle::perimeter() const {
    double length = Point2D::distance(vs[0], vs[1]);
    double width = Point2D::distance(vs[1], vs[2]);
    return 2 * (length + width);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() const {
    cout << "Vertice 0: " << vs[0] << ", Vertice 1: " << vs[1] 
         << ", Vertice 2: " << vs[2] << ", Vertice 3: " << vs[3] << endl;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Fuera de rsngo");
    }
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("No conforman rectangulo valido");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) {
        delete[] vs;
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; ++i) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
    r.print();
    return out;
}

