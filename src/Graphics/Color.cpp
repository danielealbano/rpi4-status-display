//
// Created by daalbano on 11/12/2020.
//
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
