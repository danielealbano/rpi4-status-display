#include <iostream>

#include "Graphics/Point2D.h"

#include "catch.hpp"

using namespace std;
using namespace Rpi4StatusDisplay::Graphics;

TEST_CASE("Graphics::Point2D", "[Graphics][Point2D]") {
    Point2D p0_0(0, 0);
    Point2D p1_0(10, 20);
    Point2D p1_1(10, 20);
    Point2D p2_0(40, 30);

    SECTION("Point2D(0, 0)") {
        REQUIRE(p0_0.x() == 0);
        REQUIRE(p0_0.y() == 0);
    }

    SECTION("Point2D(10, 20)") {
        REQUIRE(p1_0.x() == 10);
        REQUIRE(p1_0.y() == 20);
    }

    SECTION("Point2D(0, 0).setX(10)") {
        Point2D p(0, 0);
        p.setX(10);

        REQUIRE(p.x() == 10);
    }

    SECTION("Point2D(0, 0).setY(10)") {
        Point2D p(0, 0);
        p.setY(20);

        REQUIRE(p.y() == 20);
    }

    SECTION("Point2D(10, 20) == Point2D(10, 20) (true)") {
        REQUIRE(p1_0 == p1_1);
    }

    SECTION("Point2D(10, 20) == Point2D(40, 30) (false)") {
        REQUIRE((p1_0 == p2_0) == false);
    }

    SECTION("Point2D(10, 20) != Point2D(40, 30) (true)") {
        REQUIRE(p1_0 != p2_0);
    }

    SECTION("Point2D(10, 20) != Point2D(10, 20) (false)") {
        REQUIRE((p1_0 != p1_1) == false);
    }

    SECTION("stream << Point2D(10, 20, 30, 40)") {
        std::stringstream out;
        out << p1_0;

        REQUIRE(out.str() == "(x = 10, y = 20)");
    }
}
