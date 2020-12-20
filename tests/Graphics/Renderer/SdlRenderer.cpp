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
#include "Graphics/Point2D.h"
#include "Graphics/Size2D.h"
#include "Graphics/Rect2D.h"
#include "Graphics/Framebuffer.h"
#include "Graphics/Renderer/RendererInterface.h"
#include "Graphics/Renderer/AbstractFramebufferRenderer.h"
#include "Graphics/Renderer/SdlRenderer.h"

#include "catch.hpp"

using namespace std;
using namespace Rpi4StatusDisplay::Graphics;
using namespace Rpi4StatusDisplay::Graphics::Renderer;

void _debug_sdl_render_surface(string title, SDL_Surface* surface, int w, int h) {
    SDL_Window *win = NULL;
    SDL_Surface *winsurf = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    int posX = 100, posY = 100, width = w * 10, height = h * 10;

    win = SDL_CreateWindow(title.c_str(), posX, posY, width, height, 0);

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);
    winsurf = SDL_GetWindowSurface(win);

    SDL_Surface *output = SDL_ConvertSurface(surface, winsurf->format, 0);

    bitmapTex = SDL_CreateTextureFromSurface(renderer, output);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_UpdateWindowSurface(win);

    SDL_Event e;
    while(true){
        if (SDL_WaitEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(output);
    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyWindow(win);
}

// TODO: the test must become a test template for catch2 to test all the renderers

TEST_CASE("Graphics::Renderer::SdlRenderer", "[Graphics][Renderer][SdlRenderer]") {
    Point2D p_10_0(10, 0);
    Point2D p_20_0(20, 0);
    Size2D s0(40, 40);
    Rect2D r0(5, 7, 28, 30);
    Rect2D r1(7, 9, 24, 26);

    int depth0 = 8;
    int depthBytes0 = depth0 / 8;
    int pitch0 = s0.width() * depthBytes0;
    int colorsWhiteIndex = 1;

    int depth1 = 32;
    int depthBytes1 = depth1 / 8;
    int pitch1 = s0.width() * depthBytes1;
    int colorsWhiteRGBA = 255;

    SECTION("SdlRenderer::sdlRendererInitConstructor::sdlRendererInitConstructor()") {
        REQUIRE(SDL_WasInit(SDL_INIT_VIDEO) != 0);
    }

    SECTION("SdlRenderer(Framebuffer(Size2D(80, 80), 8, 20)).line(Point2D(0, 0), Point2D(10, 0))") {
        Framebuffer f0(s0, depth0, pitch0);
        uint8_t *data = f0.data();
        SdlRenderer sdlRenderer0(f0);

        sdlRenderer0.setColor(const_cast<Color &>(Color::Black));
        sdlRenderer0.clear();

        sdlRenderer0.setColor(const_cast<Color &>(Color::White));

        sdlRenderer0.line(p_10_0, p_20_0);
        sdlRenderer0.flush();


        // No need to take into account the pitch in the test, the line is horizontal
        for (int i = p_10_0.x() * depthBytes0; i < p_20_0.x() * depthBytes0; i++) {
            REQUIRE(data[i] == colorsWhiteIndex);
        }
    }

    SECTION("SdlRenderer(Framebuffer(Size2D(80, 80), 32, 80)).line(Point2D(0, 0), Point2D(10, 0))") {
        Framebuffer f1(s0, depth1, pitch1);
        uint8_t *data = f1.data();
        SdlRenderer sdlRenderer0(f1);

        sdlRenderer0.setColor(const_cast<Color &>(Color::Black));
        sdlRenderer0.clear();

        sdlRenderer0.setColor(const_cast<Color &>(Color::White));

        sdlRenderer0.line(p_10_0, p_20_0);
        sdlRenderer0.flush();

        // No need to take into account the pitch in the test, the line is horizontal
        for (int i = p_10_0.x() * depthBytes1; i < p_20_0.x() * depthBytes1; i++) {
            REQUIRE(data[i] == colorsWhiteRGBA);
        }
    }

    SECTION("SdlRenderer(Framebuffer(Size2D(80, 80), 8, 20)).rectOutline(Rect2D(5, 7, 28, 30))") {
        Framebuffer f0(s0, depth0, pitch0);
        uint8_t *data = f0.data();
        SdlRenderer sdlRenderer0(f0);

        sdlRenderer0.setColor(const_cast<Color &>(Color::Black));
        sdlRenderer0.clear();

        sdlRenderer0.setColor(const_cast<Color &>(Color::White));

        sdlRenderer0.rectOutline(r0);
        sdlRenderer0.flush();

        for(uint32_t indexY = r0.top(); indexY < r0.bottom(); indexY++) {
            uint32_t indexYOffset = indexY * f0.pitch();

            if (indexY == r0.top() || indexY == r0.bottom() - 1) {
                for (uint32_t i = indexYOffset + (r0.left() * depthBytes0); i < indexYOffset + (r0.right() * depthBytes0); i++) {
                    REQUIRE(data[i] == colorsWhiteIndex);
                }
            } else {
                REQUIRE(data[indexYOffset + (r0.left() * depthBytes0)] == colorsWhiteIndex);
                REQUIRE(data[indexYOffset + ((r0.right() - 1) * depthBytes0)] == colorsWhiteIndex);
            }
        }
    }

    SECTION("SdlRenderer(Framebuffer(Size2D(80, 80), 8, 20)).rectFilled(Rect2D(7, 9, 24, 26))") {
        Framebuffer f0(s0, depth0, pitch0);
        uint8_t *data = f0.data();
        SdlRenderer sdlRenderer0(f0);

        sdlRenderer0.setColor(const_cast<Color &>(Color::Black));
        sdlRenderer0.clear();

        sdlRenderer0.setColor(const_cast<Color &>(Color::White));

        sdlRenderer0.rectFilled(r1);
        sdlRenderer0.flush();

        for(uint32_t indexY = r1.top(); indexY < r1.bottom(); indexY++) {
            uint32_t indexYOffset = indexY * f0.pitch();
            for (uint32_t i = indexYOffset + (r1.left() * depthBytes0); i < indexYOffset + (r1.right() * depthBytes0); i++) {
                REQUIRE(data[i] == colorsWhiteIndex);
            }
        }
    }
}
