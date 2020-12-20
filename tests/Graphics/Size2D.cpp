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

#include "Graphics/Size2D.h"

#include "catch.hpp"

using namespace std;
using namespace Rpi4StatusDisplay::Graphics;

TEST_CASE("Graphics::Size2D", "[Graphics][Size2D]") {
    Size2D s0_0(0, 0);
    Size2D s1_0(10, 20);
    Size2D s1_1(10, 20);
    Size2D s2_0(40, 30);

    SECTION("Size2D(0, 0)") {
        REQUIRE(s0_0.width() == 0);
        REQUIRE(s0_0.height() == 0);
    }

    SECTION("Size2D(10, 20)") {
        REQUIRE(s1_0.width() == 10);
        REQUIRE(s1_0.height() == 20);
    }

    SECTION("Size2D(0, 0).setX(10)") {
        Size2D p(0, 0);
        p.setWidth(10);

        REQUIRE(p.width() == 10);
    }

    SECTION("Size2D(0, 0).setY(10)") {
        Size2D p(0, 0);
        p.setHeight(20);

        REQUIRE(p.height() == 20);
    }

    SECTION("Size2D(10, 20) == Size2D(10, 20) (true)") {
        REQUIRE(s1_0 == s1_1);
    }

    SECTION("Size2D(10, 20) == Size2D(40, 30) (false)") {
        REQUIRE((s1_0 == s2_0) == false);
    }

    SECTION("Size2D(10, 20) != Size2D(40, 30) (true)") {
        REQUIRE(s1_0 != s2_0);
    }

    SECTION("Size2D(10, 20) != Size2D(10, 20) (false)") {
        REQUIRE((s1_0 != s1_1) == false);
    }

    SECTION("stream << Size2D(10, 20, 30, 40)") {
        std::stringstream out;
        out << s1_0;

        REQUIRE(out.str() == "(width = 10, height = 20)");
    }
}
