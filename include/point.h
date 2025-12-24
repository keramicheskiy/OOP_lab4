#pragma once

#include <math.h>
#include <iostream>
#include <fmt/core.h>
#include "array.h"

template <typename T>
class Point {
public:
    T x{}, y{};

    Point() = default;

    Point(T x, T y);

    template <typename T1, typename T2>
    static double distance(const Point<T1>& a, const Point<T2>& b);

    double radialDistance() const ;

    Point<T> operator+(const Point<T>& other);

    Point<T> operator-(const Point<T>& other);

    double angle() const;

    template <typename T1, typename T2>
    bool isInsideTheSector(const Point<T1>& a, const Point<T2>& b);

    template <typename T1, typename T2, typename T3>
    static bool areCollinear(const Point<T1>& a, const Point<T2>& b, const Point<T3>& c);

    static bool hasThreeCollinearPoints(const Array<Point<T>>& points);

};

template <typename T1, typename T2>
bool operator==(const Point<T1>& a, const Point<T2>& b);

template <typename T1, typename T2>
bool operator!=(const Point<T1>& a, const Point<T2>& b);

template <typename T>
std::istream& operator>>(std::istream& is, Point<T>& p);

template <typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p);

template <typename T>
struct fmt::formatter<Point<T>> {
    constexpr auto parse(fmt::format_parse_context& ctx) { return ctx.begin(); }

    template <typename FormatContext>
    auto format(const Point<T>& p, FormatContext& ctx) {
        return fmt::format_to(ctx.out(), "({}, {})", p.x, p.y);
    }
};

#include "point.tpp"