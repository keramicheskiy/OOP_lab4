#pragma once
#include "figure.h"

template <typename T>
class Hexagon : public Figure<T> {
public:
    const size_t AMOUNT_OF_POINTS = 6;

    Hexagon();

    Hexagon(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4, Point<T> p5, Point<T> p6);

    ~Hexagon() = default;

    void read(std::istream& is) override;

    string name() const override;

};

#include "hexagon.tpp"