#pragma once
#include "figure.h"

template <typename T>
class Pentagon : public Figure<T> {
public:
    const size_t AMOUNT_OF_POINTS = 5;

    Pentagon();

    Pentagon(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4, Point<T> p5);

    ~Pentagon() = default;

    void read(std::istream& is) override;

    string name() const override;

};

#include "pentagon.tpp"