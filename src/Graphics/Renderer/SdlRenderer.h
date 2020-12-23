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

#ifndef RPI4_STATUS_DISPLAY_GRAPHICS_RENDERER_SDLRENDERER_H
#define RPI4_STATUS_DISPLAY_GRAPHICS_RENDERER_SDLRENDERER_H

namespace Rpi4StatusDisplay {
    namespace Graphics {
        namespace Renderer {
            class SdlRenderer : public AbstractFramebufferRenderer {
            private:

                /**
                 * SDL2 initialization / de-initialization using a static constructor / destructor
                 */
                static class sdlRendererInitConstructor {
                public:
                    sdlRendererInitConstructor();
                    ~sdlRendererInitConstructor();
                } sdlRendererInitConstructorInstance;

            public:
                SDL_Surface *_sdl_surface;
                SDL_Renderer *_sdl_renderer;
                SDL_Palette *_sdl_palette;

                explicit SdlRenderer(Framebuffer &framebuffer);
                ~SdlRenderer();
                SdlRenderer &setColor(Color &color) override;
                SdlRenderer &clear() override;
                SdlRenderer &flush() override;
                SdlRenderer &line(Line2D &l) override;
                SdlRenderer &rectOutline(Rect2D &r) override;
                SdlRenderer &rectFilled(Rect2D &r) override;
                SdlRenderer &text(Point2D &p, std::string &text) override;
            };
        }
    }
}

#endif //RPI4_STATUS_DISPLAY_GRAPHICS_RENDERER_SDLRENDERER_H
