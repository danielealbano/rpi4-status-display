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

#ifndef RPI4_STATUS_DISPLAY_GRAPHICS_RENDERER_RENDERERINTERFACE_H
#define RPI4_STATUS_DISPLAY_GRAPHICS_RENDERER_RENDERERINTERFACE_H

namespace Rpi4StatusDisplay {
    namespace Graphics {
        namespace Renderer {
            class RendererInterface {
            public:
                virtual RendererInterface &setColor(Color &color) = 0;
                virtual RendererInterface &flush() = 0;
                virtual RendererInterface &clear() = 0;
                virtual RendererInterface &line(Line2D &l) = 0;
                virtual RendererInterface &rectOutline(Rect2D &r) = 0;
                virtual RendererInterface &rectFilled(Rect2D &r) = 0;
                virtual RendererInterface &text(Point2D &p, std::string &text) = 0;
            };
        }
    }
}

#endif //RPI4_SSD1306_STATUS_DISPLAY_GRAPHICS_RENDERER_RENDERERINTERFACE_H
