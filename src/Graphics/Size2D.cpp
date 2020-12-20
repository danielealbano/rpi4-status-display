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
