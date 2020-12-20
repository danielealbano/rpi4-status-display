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

#include "Graphics/Color.h"

#include "catch.hpp"

using namespace std;
using namespace Rpi4StatusDisplay::Graphics;

TEST_CASE("Graphics::Color", "[Graphics][Color]") {
    Color c0_0(0, 0, 0, 0);
    Color c1_0(10, 20, 30, 40);
    Color c1_1(10, 20, 30, 40);
    Color c2_0(40, 30, 20, 10);

    SECTION("Color(0, 0, 0, 0)") {
        REQUIRE(c0_0.red() == 0);
        REQUIRE(c0_0.green() == 0);
        REQUIRE(c0_0.blue() == 0);
        REQUIRE(c0_0.alpha() == 0);
    }

    SECTION("Color(10, 20, 30, 40)") {
        REQUIRE(c1_0.red() == 10);
        REQUIRE(c1_0.green() == 20);
        REQUIRE(c1_0.blue() == 30);
        REQUIRE(c1_0.alpha() == 40);
    }

    SECTION("Color(0, 0, 0, 0).setRed(10)") {
        Color c(0, 0, 0, 0);
        c.setRed(10);

        REQUIRE(c.red() == 10);
    }

    SECTION("Color(0, 0, 0, 0).setGreen(20)") {
        Color c(0, 0, 0, 0);
        c.setGreen(20);

        REQUIRE(c.green() == 20);
    }

    SECTION("Color(0, 0, 0, 0).setBlue(30)") {
        Color c(0, 0, 0, 0);
        c.setBlue(30);

        REQUIRE(c.blue() == 30);
    }

    SECTION("Color(0, 0, 0, 0).setAlpha(40)") {
        Color c(0, 0, 0, 0);
        c.setAlpha(40);

        REQUIRE(c.alpha() == 40);
    }

    SECTION("Color(10, 20, 30, 40) == Color(10, 20, 30, 40) (true)") {
        REQUIRE(c1_0 == c1_1);
    }

    SECTION("Color(10, 20, 30, 40) == Color(40, 30, 20, 10) (false)") {
        REQUIRE((c1_0 == c2_0) == false);
    }

    SECTION("Color(10, 20, 30, 40) != Color(40, 30, 20, 10) (true)") {
        REQUIRE(c1_0 != c2_0);
    }

    SECTION("Color(10, 20, 30, 40) != Color(10, 20, 30, 40) (false)") {
        REQUIRE((c1_0 != c1_1) == false);
    }

    SECTION("stream << Color(10, 20, 30, 40)") {
        std::stringstream out;
        out << c1_0;

        REQUIRE(out.str() == "(red = 10, green = 20, blue = 30, alpha = 40)");
    }
}
