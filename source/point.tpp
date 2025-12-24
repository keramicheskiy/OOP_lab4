#include <math.h>
#include <iostream>
#include <fmt/core.h>
#include <algorithm>
#include "point.h"

template <typename T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template <typename T>
template <typename T1, typename T2>
double Point<T>::distance(const Point<T1>& a, const Point<T2>& b) {
    return std::hypot(static_cast<double>(a.x) - static_cast<double>(b.x), static_cast<double>(a.y) - static_cast<double>(b.y));
}

template <typename T>
double Point<T>::radialDistance() const {
    return std::hypot(this->x, this->y);
}

template <typename T>
Point<T> Point<T>::operator+(const Point<T>& other) {
    return Point(this->x + other.x, this->y + other.y);
}

template <typename T>
Point<T> Point<T>::operator-(const Point<T>& other) {
    return Point(this->x - other.x, this->y - other.y);
}

template <typename T>
double Point<T>::angle() const {
    double degrees = atan2(this->y, this->x) / M_PI * 180;
    if (degrees < 0) degrees += 360;
    return degrees;
}

template <typename T>
template <typename T1, typename T2>
bool Point<T>::isInsideTheSector(const Point<T1>& a, const Point<T2>& b) {
    double minAngle = std::min(a.angle(), b.angle());
    double maxAngle = std::max(a.angle(), b.angle());
    double angleC = this->angle();
    if (maxAngle - minAngle > 180) minAngle += 360;
    
    return std::min(minAngle, maxAngle) <= angleC && angleC <= std::max(minAngle, maxAngle) 
        || std::min(minAngle, maxAngle) <= angleC + 360 && angleC + 360 <= std::max(minAngle, maxAngle);
} 

template <typename T>
template <typename T1, typename T2, typename T3>
bool Point<T>::areCollinear(const Point<T1>& a, const Point<T2>& b, const Point<T3>& c) {
    double ax = static_cast<double>(a.x);
    double ay = static_cast<double>(a.y);
    double bx = static_cast<double>(b.x);
    double by = static_cast<double>(b.y);
    double cx = static_cast<double>(c.x);
    double cy = static_cast<double>(c.y);

    double allowedError = 1e-9;
    double area = ax * (by - cy) + bx * (cy - ay) + cx * (ay - by);
    return std::abs(area) < allowedError;
}

template <typename T>
bool Point<T>::hasThreeCollinearPoints(const Array<Point<T>>& points) {
    for (int i = 0; i < points.getSize(); i++)
        for (int j = 0; j < points.getSize(); j++)
            for (int k = 0; k < points.getSize(); k++)
                if (i != j && i != k && j != k && areCollinear(points.get(i), points.get(j), points.get(k)))
                    return true;
    return false;
}

template <typename T1, typename T2>
bool operator==(const Point<T1>& a, const Point<T2>& b) {
    double epsilon = 1e-9;
    return std::abs(static_cast<double>(a.x) - static_cast<double>(b.x)) < epsilon &&
           std::abs(static_cast<double>(a.y) - static_cast<double>(b.y)) < epsilon;
}

template <typename T1, typename T2>
bool operator!=(const Point<T1>& a, const Point<T2>& b) {
    return !(a == b);
}

template <typename T>
std::istream& operator>>(std::istream& is, Point<T>& p) {
    is >> p.x >> p.y;
    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
    os << fmt::format("({}, {})", p.x, p.y);
    return os;
}

