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

#include "Color.h"

namespace Rpi4StatusDisplay {
    namespace Graphics {
        const Color Color::White(255, 255, 255, 255);
        const Color Color::Black(0, 0, 0, 255);

        Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
            this->setRed(red);
            this->setGreen(green);
            this->setBlue(blue);
            this->setAlpha(alpha);
        }

        uint8_t Color::red() const {
            return this->_red;
        }

        void Color::setRed(uint8_t red) {
            this->_red = red;
        }

        uint8_t Color::green() const {
            return this->_green;
        }

        void Color::setGreen(uint8_t green) {
            this->_green = green;
        }

        uint8_t Color::blue() const {
            return this->_blue;
        }

        void Color::setBlue(uint8_t blue) {
            this->_blue = blue;
        }

        uint8_t Color::alpha() const {
            return this->_alpha;
        }

        void Color::setAlpha(uint8_t alpha) {
            this->_alpha = alpha;
        }

        bool operator == (const Color &c1, const Color &c2) {
            return
                c1.red() == c2.red() &&
                c1.blue() == c2.blue() &&
                c1.green() == c2.green() &&
                c1.alpha() == c2.alpha();
        }

        bool operator != (const Color &c1, const Color &c2) {
            return !(c1 == c2);
        }

        std::ostream & operator<<(std::ostream & output, const Color &c) {
            output <<
                   "(" <<
                   "red = " << ((int)c.red()) << ", green = " << ((int)c.green()) <<
                   ", blue = " << ((int)c.blue()) << ", alpha = " << ((int)c.alpha()) <<
                   ")";
            return output;
        }
    }
}
