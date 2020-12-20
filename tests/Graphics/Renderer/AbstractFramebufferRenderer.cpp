#include <iostream>

#include "Graphics/Color.h"
#include "Graphics/Point2D.h"
#include "Graphics/Size2D.h"
#include "Graphics/Rect2D.h"
#include "Graphics/Framebuffer.h"
#include "Graphics/Renderer/RendererInterface.h"
#include "Graphics/Renderer/AbstractFramebufferRenderer.h"

#include "catch.hpp"

using namespace std;
using namespace Rpi4StatusDisplay::Graphics;
using namespace Rpi4StatusDisplay::Graphics::Renderer;

#define EMPTY_OVERRIDED_CLASS_METHOD(METHOD_NAME, ...) \
    void METHOD_NAME(__VA_ARGS__) override { \
    }

class AbstractRendererTestWrapper : public AbstractFramebufferRenderer {
public:
    explicit AbstractRendererTestWrapper(Framebuffer &framebuffer) : AbstractFramebufferRenderer(framebuffer) {
        // do nothing
    }

    EMPTY_OVERRIDED_CLASS_METHOD(setColor, Color &c);
    EMPTY_OVERRIDED_CLASS_METHOD(flush);
    EMPTY_OVERRIDED_CLASS_METHOD(clear);
    EMPTY_OVERRIDED_CLASS_METHOD(text, std::string &text);
    EMPTY_OVERRIDED_CLASS_METHOD(line, Point2D &p1, Point2D &p2);
    EMPTY_OVERRIDED_CLASS_METHOD(rectOutline, Rect2D &r);
    EMPTY_OVERRIDED_CLASS_METHOD(rectFilled, Rect2D &r);
};

TEST_CASE("Graphics::Renderer::AbstractFramebufferRenderer", "[Graphics][Renderer][AbstractFramebufferRenderer]") {
    Size2D s0(20, 40);
    Framebuffer f0(s0, 3, s0.width() * 3);

    AbstractRendererTestWrapper abstractRendererTestWrapper0(f0);

    SECTION("AbstractFramebufferRenderer(Framebuffer(Size2D(20, 40)))") {
        REQUIRE(&abstractRendererTestWrapper0.framebuffer() == &f0);
    }
}
