//
// Created by daalbano on 19/12/2020.
//
#include <iostream>

#include "Graphics/Color.h"
#include "Graphics/Size2D.h"
#include "Graphics/Point2D.h"
#include "Graphics/Rect2D.h"
#include "Graphics/Framebuffer.h"
#include "Graphics/Renderer/RendererInterface.h"

#include "AbstractFramebufferRenderer.h"

namespace Rpi4StatusDisplay {
    namespace Graphics {
        namespace Renderer {
            AbstractFramebufferRenderer::AbstractFramebufferRenderer(Framebuffer &framebuffer) : _framebuffer(framebuffer) {
                // do nothing
            }

            Framebuffer &AbstractFramebufferRenderer::framebuffer() {
                return this->_framebuffer;
            }
        }
    }
}
