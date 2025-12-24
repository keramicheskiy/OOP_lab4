#pragma once
#include "figure.h"

template <typename T>
class Octagon : public Figure<T> {
public:
    const size_t AMOUNT_OF_POINTS = 8;

    Octagon();

    Octagon(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4, Point<T> p5, Point<T> p6, Point<T> p7, Point<T> p8);

    ~Octagon() = default;

    void read(std::istream& is);

    string name() const;

};

#include "octagon.tpp"