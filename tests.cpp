#include <gtest/gtest.h>
#include <figure.h>
#include <pentagon.h>
#include <octagon.h>
#include <hexagon.h>

TEST(Lab4Tests, AreaTest) {
    Pentagon<double> pentagon = {{0, 0}, {-1, 3}, {2, 5}, {4, 2.5}, {3, 0}};
    Hexagon<double> hexagon = {{5, 1}, {3.26795, 2}, {5, 3}, {7, 3}, {8.73205, 2}, {7, 1}};
    Octagon<int> octagon = {{0, 2}, {0, 3}, {2, 5}, {3, 5}, {5, 4}, {5, 3}, {3, 1}, {2, 0}};
    double epsilon = 5e-3;

    EXPECT_NEAR(pentagon.getArea(), 16.75, epsilon);
    EXPECT_NEAR(hexagon.getArea(), 7.46, epsilon);
    EXPECT_NEAR(octagon.getArea(), 15.5, epsilon);
}

TEST(Lab4Tests, CenterTest) {
    Pentagon<double> pentagon = {{0, 0}, {-1, 3}, {2, 5}, {4, 2.5}, {3, 0}};
    Hexagon<double> hexagon = {{5, 1}, {3.26795, 2}, {5, 3}, {7, 3}, {8.73205, 2}, {7, 1}};
    Octagon<int> octagon = {{0, 2}, {0, 3}, {2, 5}, {3, 5}, {5, 4}, {5, 3}, {3, 1}, {2, 0}};

    EXPECT_EQ(pentagon.getCenter(), Point(1.6, 2.1));
    EXPECT_EQ(hexagon.getCenter(), Point(6, 2));
    EXPECT_EQ(octagon.getCenter(), Point(2, 2));
}