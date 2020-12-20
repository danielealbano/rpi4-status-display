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
