//
// Created by daalbano on 19/12/2020.
//

#ifndef RPI4_STATUS_DISPLAY_GRAPHICS_RENDERER_ABSTRACTFRAMEBUFFERRENDERER_H
#define RPI4_STATUS_DISPLAY_GRAPHICS_RENDERER_ABSTRACTFRAMEBUFFERRENDERER_H

namespace Rpi4StatusDisplay {
    namespace Graphics {
        namespace Renderer {
            class AbstractFramebufferRenderer : public RendererInterface {
            private:
                Framebuffer &_framebuffer;
            public:
                explicit AbstractFramebufferRenderer(Framebuffer &framebuffer);
                virtual Framebuffer &framebuffer();
            };
        }
    }
}


#endif //RPI4_STATUS_DISPLAY_GRAPHICS_RENDERER_ABSTRACTFRAMEBUFFERRENDERER_H
