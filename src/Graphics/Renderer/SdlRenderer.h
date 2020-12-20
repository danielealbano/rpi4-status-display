//
// Created by daalbano on 19/12/2020.
//

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
                void setColor(Color &color) override;
                void clear() override;
                void flush() override;
                void line(Point2D &p1, Point2D &p2) override;
                void rectOutline(Rect2D &r) override;
                void rectFilled(Rect2D &r) override;
                void text(std::string &text) override;
            };
        }
    }
}

#endif //RPI4_STATUS_DISPLAY_GRAPHICS_RENDERER_SDLRENDERER_H
