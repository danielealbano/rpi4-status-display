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

#ifndef RPI4_STATUS_DISPLAY_GRAPHICS_COLOR_H
#define RPI4_STATUS_DISPLAY_GRAPHICS_COLOR_H

namespace Rpi4StatusDisplay {
    namespace Graphics {
        class Color {
        protected:
            uint8_t _red;
            uint8_t _green;
            uint8_t _blue;
            uint8_t _alpha;

        public:
            Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
            uint8_t red() const;
            void setRed(uint8_t red);
            uint8_t green() const;
            void setGreen(uint8_t green);
            uint8_t blue() const;
            void setBlue(uint8_t blue);
            uint8_t alpha() const;
            void setAlpha(uint8_t alpha);

            friend std::ostream & operator << (std::ostream &output, const Color &p);

            friend bool operator == (const Color &p1, const Color &p2);
            friend bool operator != (const Color &p1, const Color &p2);

            /**
             * Predefined colors
             */
            static const Color White;
            static const Color Black;
        };
    }
}

#endif //RPI4_STATUS_DISPLAY_GRAPHICS_COLOR_H
