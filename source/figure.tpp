#include <ostream>
#include "point.h"
#include "array.h"
#include <numeric>
#include <limits>
#include <math.h>
#include "figure.h"

template <typename T>
double Figure<T>::triangleArea(const Point<T>& A, const Point<T>&B, const Point<T>& C) {
    double a = Point<T>::distance(B, C);
    double b = Point<T>::distance(A, C);
    double c = Point<T>::distance(B, A);
    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}


template <typename T>
Figure<T>::Figure(std::initializer_list<Point<T>> points) {
    if (points.getSize() < 3) throw runtime_error("Any figure must have at least 3 points!");

    for (const auto p : points)
        this->points.push(std::make_shared<Point<T>>(p));

    if (Point<T>::hasThreeCollinearPoints(points)) throw runtime_error("Three or more points are collinear!");
}


template <typename T>
Figure<T>::Figure(Array<Point<T>>& points) : points(points) {
    if (points.getSize() < 3) throw runtime_error("Any figure must have at least 3 points!");

    if (Point<T>::hasThreeCollinearPoints(points)) throw runtime_error("Three or more points are collinear!");
}

template <typename T>
Point<double> Figure<T>::getCenter() const {
    T sumX{}, sumY{};
    for (int i = 0; i < points.getSize(); ++i) {
        sumX += points[i]->x;
        sumY += points[i]->y;
    }
    return Point<double>(sumX / static_cast<T>(points.getSize()), sumY / static_cast<T>(points.getSize()));
}

template <typename T>
double Figure<T>::getArea() const {
    long double res{0.0};
    for (int i = 0; i + 1 < points.getSize(); ++i) {
        res += points[i]->x * static_cast<long double>(points[i + 1]->y);
        res -= points[i + 1]->x * static_cast<long double>(points[i]->y);
    }
    res += static_cast<long double>(points[points.getSize() - 1]->x) * static_cast<long double>(points[0]->y);
    res -= static_cast<long double>(points[0]->x) * static_cast<long double>(points[points.getSize() - 1]->y);
    return std::abs(res / 2.0);
}

template <typename T>
Figure<T>& Figure<T>::operator=(const Figure<T>& other) {
    if (this == &other) return *this;

    points = other.points;

    return *this;
}

template <typename T>
Figure<T>& Figure<T>::operator=(Figure<T>&& other) noexcept {
    if (this == &other) return *this;

    points = std::move(other.points);

    return *this;
}

template <typename T1, typename T2>
bool operator==(const Figure<T1>& a, const Figure<T2>& b) {
    if (a.points.getSize() != b.points.getSize()) return false;
    for (Point p : a.points) {
        if (!b.points.contains(p)) return false;
    }
    return true;
}

template <typename T1, typename T2>
bool operator!=(const Figure<T1>& a, const Figure<T2>& b) {
    return !(a == b);
}

template <typename T>
void Figure<T>::read(std::istream& is) {
    this->points.clear();
    Point<T> point;
    while (is >> point) {
        this->points.push(std::make_shared<Point<T>>(point));
    }
    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
void Figure<T>::print(std::ostream& os) {
    for (int i = 0; i < this->points.getSize(); i++) {
        os << *this->points[i] << ((i != this->points.getSize() - 1)? ", " : "");
    }
}

template <typename T>
std::istream& operator>>(std::istream& is, Figure<T>& figure) {
    figure.read(is);
    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Figure<T>& figure) {
    figure.print(os);
    return os;
}

template <typename T>
Figure<T>::operator double() const {
    return getArea();
}

template <typename T>
string Figure<T>::name() const {
    return "figure";
}

