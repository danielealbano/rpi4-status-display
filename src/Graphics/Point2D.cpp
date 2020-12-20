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

#include "Point2D.h"

namespace Rpi4StatusDisplay {
    namespace Graphics {
        Point2D::Point2D(int x, int y) {
            this->setX(x);
            this->setY(y);
        }

        int Point2D::x() const  {
            return this->_x;
        }

        void Point2D::setX(int x) {
            this->_x = x;
        }

        int Point2D::y() const {
            return this->_y;
        }

        void Point2D::setY(int y) {
            this->_y = y;
        }

        bool operator == (const Point2D &p1, const Point2D &p2) {
            return p1.x() == p2.x() && p1.y() == p2.y();
        }

        bool operator != (const Point2D &p1, const Point2D &p2) {
            return !(p1 == p2);
        }

        std::ostream & operator << (std::ostream & output, const Point2D &p) {
            output <<
                   "(" <<
                   "x = " << p.x() << ", y = " << p.y() <<
                   ")";
            return output;
        }
    }
}
