/**
 * Copyright 2020-2021 Albano Daniele Salvatore
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 * disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdint>
#include <iostream>
#include <sstream>

#include "Graphics/Point2D.h"
#include "Graphics/Line2D.h"

#include <catch2/catch.hpp>

using namespace std;
using namespace Rpi4StatusDisplay::Graphics;

TEST_CASE("Graphics::Line2D", "[Graphics][Line2D]") {
    Point2D point_0_0(0, 0);
    Point2D point_10_20_a(10, 20);
    Point2D point_10_20_b(10, 20);
    Point2D point_40_30(40, 30);




    Line2D line_0_0_10_20_a(point_0_0, point_10_20_a);
    Line2D line_0_0_10_20_b(point_0_0, point_10_20_b);
    Line2D line_10_20_0_0(point_10_20_b, point_0_0);
    Line2D line_0_0_40_30(point_0_0, point_40_30);

    SECTION("Line2D.point1() returns the first point") {
        REQUIRE(&line_0_0_10_20_a.point1() == &point_0_0);
    }

    SECTION("Line2D.point2() returns the second point") {
        REQUIRE(&line_0_0_10_20_a.point2() == &point_10_20_a);
    }

    SECTION("Line.2D.setPoint1() updates the first point") {
        Point2D point_a(0, 0);
        Point2D point_b(10, 0);
        Point2D point_c(0, 10);

        Line2D line(point_a, point_b);
        line.setPoint1(point_c);

        REQUIRE(line.point1() == point_c);
    }

    SECTION("Line.2D.setPoint1() updates the second point") {
        Point2D point_a(0, 0);
        Point2D point_b(0, 10);
        Point2D point_c(10, 0);

        Line2D line(point_a, point_b);
        line.setPoint2(point_c);

        REQUIRE(line.point2() == point_c);
    }

    SECTION("Compare two lines - (line_0_0_10_20_a == line_0_0_10_20_b) is true") {
        REQUIRE(line_0_0_10_20_a == line_0_0_10_20_b);
    }

    SECTION("Compare two lines - (line_0_0_10_20_a == line_0_0_40_30) is false") {
        REQUIRE((line_0_0_10_20_a == line_0_0_40_30) == false);
    }

    SECTION("Compare two lines - (line_0_0_10_20_a != line_0_0_40_30) is false") {
        REQUIRE(line_0_0_10_20_a != line_0_0_40_30);
    }

    SECTION("Compare two lines - (line_0_0_10_20_a != line_0_0_10_20_b) is false") {
        REQUIRE((line_0_0_10_20_a != line_0_0_10_20_b) == false);
    }

    SECTION("The << operator produces a textual representation of the line") {
        std::stringstream out;
        out << line_10_20_0_0;
        std::string a = out.str();

        REQUIRE(out.str() == "(point1 = (left = 10, top = 20), point2 = (left = 0, top = 0))");
    }
}
