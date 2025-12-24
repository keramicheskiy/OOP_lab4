#include "pentagon.h"

template <typename T>
Pentagon<T>::Pentagon() {
    this->points.clear();
    for (int i = 0; i < AMOUNT_OF_POINTS; ++i) {
        this->points.push(std::make_shared<Point<T>>(0, 0));
    }
}

template <typename T>
Pentagon<T>::Pentagon(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4, Point<T> p5) {
    this->points.clear();
    this->points.push(std::make_shared<Point<T>>(p1));
    this->points.push(std::make_shared<Point<T>>(p2));
    this->points.push(std::make_shared<Point<T>>(p3));
    this->points.push(std::make_shared<Point<T>>(p4));
    this->points.push(std::make_shared<Point<T>>(p5));
}

template <typename T>
void Pentagon<T>::read(std::istream& is) {
    this->points.clear();
    for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
        Point<T> point;
        is >> point;
        this->points.push(std::make_shared<Point<T>>(point));
    }
}

template <typename T>
string Pentagon<T>::name() const {
    return "pentagon";
}
