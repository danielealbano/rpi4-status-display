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
        Point2D::Point2D(int left, int top) {
            this->setLeft(left);
            this->setTop(top);
        }

        int Point2D::left() const  {
            return this->_left;
        }

        void Point2D::setLeft(int left) {
            this->_left = left;
        }

        int Point2D::top() const {
            return this->_top;
        }

        void Point2D::setTop(int top) {
            this->_top = top;
        }

        bool operator == (const Point2D &point1, const Point2D &point2) {
            return point1.left() == point2.left() && point1.top() == point2.top();
        }

        bool operator != (const Point2D &point1, const Point2D &point2) {
            return !(point1 == point2);
        }

        std::ostream & operator << (std::ostream & output, const Point2D &point) {
            output <<
                   "(" <<
                   "left = " << point.left() << ", top = " << point.top() <<
                   ")";
            return output;
        }
    }
}
