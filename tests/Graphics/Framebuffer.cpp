#include <iostream>

#include "Graphics/Size2D.h"
#include "Graphics/Framebuffer.h"

#include "catch.hpp"

using namespace std;
using namespace Rpi4StatusDisplay::Graphics;

TEST_CASE("Graphics::Framebuffer", "[Graphics][Framebuffer]") {
    Size2D s0(0, 0);
    Size2D s1(20, 40);
    Size2D s2(30, 50);
    int depth = 24;
    int depthBytes = depth / 8;

    Framebuffer f1(s1, depth, s1.width() * depthBytes);
    Framebuffer f2(s2, depth, s2.width() * depthBytes);

    SECTION("Framebuffer(Size2D(0, 0), 3, 0)") {
        // todo
    }

    SECTION("Framebuffer(Size2D(20, 40), 3, 60).size()") {
        REQUIRE(f1.size().width() == s1.width());
        REQUIRE(f1.size().height() == s1.height());
    }

    SECTION("Framebuffer(Size2D(20, 40), 3, 60).depth()") {
        REQUIRE(f1.depth() == depth);
    }

    SECTION("Framebuffer(Size2D(20, 40), 3, 60).pitch()") {
        REQUIRE(f1.pitch() == s1.width() * depthBytes);
    }

    SECTION("Framebuffer(Size2D(20, 40), 3, 60).dataLength()") {
        REQUIRE(f1.dataLength() == s1.width() * depthBytes * s1.height());
    }

    SECTION("Framebuffer(Size2D(20, 40), 3, 60).data()") {
        REQUIRE(f1.data() != nullptr);
    }

    SECTION("Framebuffer(Size2D(30, 50), 3, 90).size()") {
        REQUIRE(f2.size().width() == s2.width());
        REQUIRE(f2.size().height() == s2.height());
    }

    SECTION("Framebuffer(Size2D(20, 40), 3, 90).depth()") {
        REQUIRE(f2.depth() == depth);
    }

    SECTION("Framebuffer(Size2D(20, 40), 3, 90).pitch()") {
        REQUIRE(f2.pitch() == s2.width() * depthBytes);
    }

    SECTION("Framebuffer(Size2D(30, 50), 3, 90).dataLength()") {
        REQUIRE(f2.dataLength() == s2.width() * depthBytes * s2.height());
    }

    SECTION("Framebuffer(Size2D(30, 50), 3, 90).data()") {
        REQUIRE(f2.data() != nullptr);
    }

    SECTION("stream << Framebuffer(Size2D(20, 40), 3, 60)") {
        std::string prefix = "(size.width = 20, size.height = 40, depth = 24, pitch = 60, dataLength = 2400, data = ";
        std::string suffix = ")";
        std::stringstream out;
        out << f1;
        std::string a = out.str();

        REQUIRE(out.str().find(prefix) == 0);
        REQUIRE(out.str().rfind(suffix) > prefix.length() + 2);
    }
}
