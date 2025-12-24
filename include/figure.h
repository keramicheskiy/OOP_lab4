#pragma once

#include <ostream>
#include "point.h"
#include "array.h"
#include <numeric>
#include <math.h>
#include <variant>

template <typename T>
class Figure {
private:
    static double triangleArea(const Point<T>& A, const Point<T>&B, const Point<T>& C);

public:
    Array<std::shared_ptr<Point<T>>> points;

    Figure() = default;

    Figure(std::initializer_list<Point<T>> points);

    Figure(Array<Point<T>>& points);

    virtual ~Figure() = default;

    Point<double> getCenter() const;

    double getArea() const;

    Figure<T>& operator=(const Figure<T>& other);

    Figure<T>& operator=(Figure<T>&& other) noexcept;

    virtual void read(std::istream& is);

    virtual void print(std::ostream& os);

    operator double() const;

    virtual string name() const;

};

template <typename T1, typename T2>
bool operator==(const Figure<T1>& a, const Figure<T2>& b);

template <typename T1, typename T2>
bool operator!=(const Figure<T1>& a, const Figure<T2>& b);

template <typename T>
std::ostream& operator<<(std::ostream& os, Figure<T>& figure);

template <typename T>
std::istream& operator>>(std::istream& is, Figure<T>& figure);

#include "figure.tpp"