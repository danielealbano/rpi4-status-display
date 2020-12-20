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
