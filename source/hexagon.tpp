#include "hexagon.h"

template <typename T>
Hexagon<T>::Hexagon() {
    this->points.clear();
    for (int i = 0; i < AMOUNT_OF_POINTS; ++i) {
        this->points.push(std::make_shared<Point<T>>(0, 0));
    }
}

template <typename T>
Hexagon<T>::Hexagon(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4, Point<T> p5, Point<T> p6) {
    this->points.clear();
    this->points.push(std::make_shared<Point<T>>(p1));
    this->points.push(std::make_shared<Point<T>>(p2));
    this->points.push(std::make_shared<Point<T>>(p3));
    this->points.push(std::make_shared<Point<T>>(p4));
    this->points.push(std::make_shared<Point<T>>(p5));
    this->points.push(std::make_shared<Point<T>>(p6));
}

template <typename T>
void Hexagon<T>::read(std::istream& is) {
    this->points.clear();
    for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
        Point<T> point;
        is >> point;
        this->points.push(std::make_shared<Point<T>>(point));
    }
}

template <typename T>
string Hexagon<T>::name() const {
    return "hexagon";
}

