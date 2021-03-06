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
#include "Graphics/Size2D.h"
#include "Graphics/Rect2D.h"

#include <catch2/catch.hpp>

using namespace std;
using namespace Rpi4StatusDisplay::Graphics;

TEST_CASE("Graphics::Rect2D", "[Graphics][Rect2D]") {
    Point2D p0_r0(0, 0);
    Size2D s0_r0(0, 0);
    Point2D p1_r1(10, 20);
    Size2D s1_r1(30, 40);
    Point2D p2_r2(40, 30);
    Size2D s2_r2(20, 10);

    Rect2D r0_0(p0_r0, s0_r0);
    Rect2D r1_0(p1_r1, s1_r1);
    Rect2D r1_1(p1_r1, s1_r1);
    Rect2D r2_0(p2_r2, s2_r2);

    Point2D p_in(r1_0.left() + 1, r1_0.top() + 1);
    Point2D p_out_top_left_corner(r1_0.left() - 1, r1_0.top() - 1);
    Point2D p_out_bottom_right_corner(r1_0.right() + 1, r1_0.bottom() + 1);
    Point2D p_on_top_left_corner(r1_0.left() + 1, r1_0.top() + 1);
    Point2D p_on_bottom_right_corner(r1_0.right(), r1_0.bottom());

    SECTION("Rect2D(0, 0, 0, 0)") {
        REQUIRE(r0_0.left() == 0);
        REQUIRE(r0_0.top() == 0);
        REQUIRE(r0_0.width() == 0);
        REQUIRE(r0_0.height() == 0);
        REQUIRE(r0_0.right() == 0);
        REQUIRE(r0_0.bottom() == 0);
    }

    SECTION("Rect2D(10, 20, 30, 40)") {
        REQUIRE(r1_0.left() == 10);
        REQUIRE(r1_0.top() == 20);
        REQUIRE(r1_0.width() == 30);
        REQUIRE(r1_0.height() == 40);
        REQUIRE(r1_0.right() == 10 + 30);
        REQUIRE(r1_0.bottom() == 20 + 40);
    }

    SECTION("Rect2D(10, 20, 30, 40)") {
        Rect2D rect(10, 20, 30, 40);
        REQUIRE(r1_0.left() == 10);
        REQUIRE(r1_0.top() == 20);
        REQUIRE(r1_0.width() == 30);
        REQUIRE(r1_0.height() == 40);
        REQUIRE(r1_0.right() == 10 + 30);
        REQUIRE(r1_0.bottom() == 20 + 40);
    }

    SECTION("Rect2D(0, 0, 0, 0).setLeft(10)") {
        Point2D p0(0, 0);
        Size2D s0(0, 0);
        Point2D p1(10, 20);
        Rect2D r(p0, s0);
        r.setPoint(p1);

        REQUIRE(r.left() == 10);
        REQUIRE(r.right() == 10);
        REQUIRE(r.top() == 20);
        REQUIRE(r.bottom() == 20);
    }

    SECTION("Rect2D(0, 0, 0, 0).setWidth(10)") {
        Point2D p0(0, 0);
        Size2D s0(0, 0);
        Size2D s1(30, 40);
        Rect2D r(p0, s0);
        r.setSize(s1);

        REQUIRE(r.left() == 0);
        REQUIRE(r.right() == 30);
        REQUIRE(r.top() == 0);
        REQUIRE(r.bottom() == 40);
    }

    SECTION("Rect2D(10, 20, 30, 40).contains(Point2D(11, 21)) (true)") {
        REQUIRE(r1_0.contains(p_in));
    }

    SECTION("Rect2D(10, 20, 30, 40).contains(Point2D(9, 19)) (false)") {
        REQUIRE(!r1_0.contains(p_out_top_left_corner));
    }

    SECTION("Rect2D(10, 20, 30, 40).contains(Point2D(41, 61)) (false)") {
        REQUIRE(!r1_0.contains(p_out_bottom_right_corner));
    }

    SECTION("Rect2D(10, 20, 30, 40).contains(Point2D(10, 20)) (true)") {
        REQUIRE(r1_0.contains(p_on_top_left_corner));
    }

    SECTION("Rect2D(10, 20, 30, 40).contains(Point2D(40, 60)) (true)") {
        REQUIRE(r1_0.contains(p_on_bottom_right_corner));
    }

    SECTION("Rect2D(10, 20, 30, 40) == Rect2D(10, 20, 30, 40) (true)") {
        REQUIRE(r1_0 == r1_1);
    }

    SECTION("Rect2D(10, 20, 30, 40) == Rect2D(40, 30, 20, 10) (false)") {
        REQUIRE((r1_0 == r2_0) == false);
    }

    SECTION("Rect2D(10, 20, 30, 40) != Rect2D(40, 30, 20, 10) (true)") {
        REQUIRE(r1_0 != r2_0);
    }

    SECTION("Rect2D(10, 20, 30, 40) != Rect2D(10, 20, 30, 40) (false)") {
        REQUIRE((r1_0 != r1_1) == false);
    }

    SECTION("stream << Rect2D(10, 20, 30, 40)") {
        std::stringstream out;
        out << r1_0;

        REQUIRE(out.str() == "(left = 10, top = 20, width = 30, height = 40)");
    }
}
