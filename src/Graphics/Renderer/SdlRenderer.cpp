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

#include <SDL.h>

#include "Graphics/Color.h"
#include "Graphics/Size2D.h"
#include "Graphics/Point2D.h"
#include "Graphics/Rect2D.h"
#include "Graphics/Framebuffer.h"
#include "Graphics/Renderer/RendererInterface.h"
#include "Graphics/Renderer/AbstractFramebufferRenderer.h"

#include "SdlRenderer.h"

namespace Rpi4StatusDisplay {
    namespace Graphics {
        namespace Renderer {
            /**
             * SDL2 initialization / de-initialization using a static constructor / destructor
             */
            SdlRenderer::sdlRendererInitConstructor SdlRenderer::sdlRendererInitConstructorInstance;
            SdlRenderer::sdlRendererInitConstructor::sdlRendererInitConstructor() {
                if (SDL_Init(SDL_INIT_VIDEO) != 0) {
                    std::string errorStr(SDL_GetError());
                    SDL_Log("Unable to initialize SDL: %s", errorStr.c_str());

                    throw std::runtime_error(errorStr);
                }
            }
            SdlRenderer::sdlRendererInitConstructor::~sdlRendererInitConstructor() {
                SDL_Quit();
            }

            SdlRenderer::SdlRenderer(Framebuffer &framebuffer) : AbstractFramebufferRenderer(framebuffer) {
                int pixelFormat;

                // TODO: review constructor, Valgrind reports "Uninitialised value was created by a stack
                //       allocation", need to investigate the source of the warning

                // TODO: another hack, the palette, if required, should be passed down from the display through the
                //       framebuffer as the colors in it will be indexed via the palette. Only black and white rendering
                //       is currently supported, so only 2 colors are going to be initialized.
                //       The two colors have the same R, G and B values so mapping everything to red is fine.
                int colors_count = 2;
                SDL_Color colors[colors_count];
                colors[0].r = colors[0].g = colors[0].b = Color::Black.red();
                colors[1].r = colors[1].g = colors[1].b = Color::White.red();

                // TODO: Need to properly handle the pixel format as different displays may use different formats but
                //       currently only the monochrome oled SSD1306 controller is supported.
                switch (framebuffer.depth()) {
                    case 8:
                        pixelFormat = SDL_PIXELFORMAT_INDEX8;
                        break;
                    case 24:
                        pixelFormat = SDL_PIXELFORMAT_RGB24;
                        break;
                    case 32:
                        pixelFormat = SDL_PIXELFORMAT_RGBA32;
                        break;
                    default:
                        throw std::runtime_error("Unsupported depth");
                }

                // Creates an RGB surface from the framebuffer memory
                this->_sdl_surface = SDL_CreateRGBSurfaceWithFormatFrom(
                        (void*)framebuffer.data(),
                        framebuffer.size().width(),
                        framebuffer.size().height(),
                        framebuffer.depth(),
                        framebuffer.pitch(),
                        pixelFormat);
                if (this->_sdl_surface == nullptr) {
                    std::string errorStr(SDL_GetError());
                    SDL_Log("Unable to initialize surface for framebuffer: %s", errorStr.c_str());

                    throw std::runtime_error(errorStr);
                }

                // Preconfigure a palette
                if (pixelFormat == SDL_PIXELFORMAT_INDEX8) {
                    this->_sdl_palette = SDL_AllocPalette(colors_count);
                    SDL_SetPaletteColors(this->_sdl_palette, colors, 0, colors_count);
                    SDL_SetSurfacePalette(this->_sdl_surface, this->_sdl_palette);
                }

                // Allocates a renderer for the surface
                this->_sdl_renderer = SDL_CreateSoftwareRenderer(this->_sdl_surface);
                if (this->_sdl_renderer == nullptr) {
                    std::string errorStr(SDL_GetError());
                    SDL_Log("Unable to renderer: %s", errorStr.c_str());

                    throw std::runtime_error(errorStr);
                }
            }

            SdlRenderer::~SdlRenderer() {
                if (this->_sdl_palette != nullptr) {
                    SDL_FreePalette(this->_sdl_palette);
                }
                SDL_DestroyRenderer(this->_sdl_renderer);
                SDL_FreeSurface(this->_sdl_surface);
            };

            SdlRenderer &SdlRenderer::setColor(Color &color) {
                SDL_SetRenderDrawColor(
                        this->_sdl_renderer,
                        color.red(), color.green(), color.blue(), color.alpha());

                return *this;
            }

            SdlRenderer &SdlRenderer::clear() {
                SDL_RenderClear(this->_sdl_renderer);

                return *this;
            }

            SdlRenderer &SdlRenderer::flush() {
                SDL_RenderPresent(this->_sdl_renderer);

                return *this;
            }

            SdlRenderer &SdlRenderer::line(Point2D &p1, Point2D &p2) {
                SDL_RenderDrawLine(
                        this->_sdl_renderer,
                        p1.left(), p1.top(),
                        p2.left(), p2.top());

                return *this;
            }

            SdlRenderer &SdlRenderer::rectOutline(Rect2D &r) {
                SDL_Rect sdl_rect = {
                        r.left(), r.top(),
                        r.width(), r.height()
                };

                SDL_RenderDrawRect(this->_sdl_renderer, &sdl_rect);

                return *this;
            }

            SdlRenderer &SdlRenderer::rectFilled(Rect2D &r) {
                SDL_Rect sdl_rect = {
                        r.left(), r.top(),
                        r.width(), r.height()
                };

                SDL_RenderFillRect(this->_sdl_renderer, &sdl_rect);

                return *this;
            }

            SdlRenderer &SdlRenderer::text(Point2D &p, std::string &text) {
                // todo
                return *this;
            }
        }
    }
}
