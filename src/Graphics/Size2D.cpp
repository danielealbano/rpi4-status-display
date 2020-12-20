//
// Created by daalbano on 11/12/2020.
//
#include <iostream>

#include "Size2D.h"

namespace Rpi4StatusDisplay {
    namespace Graphics {
        Size2D::Size2D(int width, int height) {
            this->setWidth(width);
            this->setHeight(height);
        }

        int Size2D::width() const  {
            return this->_width;
        }

        void Size2D::setWidth(int width) {
            this->_width = width;
        }

        int Size2D::height() const {
            return this->_height;
        }

        void Size2D::setHeight(int height) {
            this->_height = height;
        }

        bool operator == (const Size2D &s1, const Size2D &s2) {
            return s1.width() == s2.width() && s1.height() == s2.height();
        }

        bool operator != (const Size2D &s1, const Size2D &s2) {
            return !(s1 == s2);
        }

        std::ostream & operator << (std::ostream & output, const Size2D &s) {
            output <<
                   "(" <<
                   "width = " << s.width() << ", height = " << s.height() <<
                   ")";
            return output;
        }
    }
}
