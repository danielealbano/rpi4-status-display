//
// Created by daalbano on 11/12/2020.
//

#ifndef RPI4_STATUS_DISPLAY_GRAPHICS_RENDERER_RENDERERINTERFACE_H
#define RPI4_STATUS_DISPLAY_GRAPHICS_RENDERER_RENDERERINTERFACE_H

namespace Rpi4StatusDisplay {
    namespace Graphics {
        namespace Renderer {
            class RendererInterface {
            public:
                virtual void setColor(Color &color) = 0;
                virtual void flush() = 0;
                virtual void clear() = 0;
                virtual void line(Point2D &p1, Point2D &p2) = 0;
                virtual void rectOutline(Rect2D &r) = 0;
                virtual void rectFilled(Rect2D &r) = 0;
                virtual void text(std::string &text) = 0;
            };
        }
    }
}

#endif //RPI4_SSD1306_STATUS_DISPLAY_GRAPHICS_RENDERER_RENDERERINTERFACE_H
