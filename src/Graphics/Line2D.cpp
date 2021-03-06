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
#include "Line2D.h"

namespace Rpi4StatusDisplay {
    namespace Graphics {
        Line2D::Line2D(Point2D &point1, Point2D &point2) : _point1(point1), _point2(point2) {
        }

        Point2D &Line2D::point1() const  {
            return this->_point1;
        }

        void Line2D::setPoint1(Point2D &point1) {
            this->_point1 = point1;
        }

        Point2D &Line2D::point2() const {
            return this->_point2;
        }

        void Line2D::setPoint2(Point2D &point2) {
            this->_point2 = point2;
        }

        bool operator == (const Line2D &line1, const Line2D &line2) {
            return
                    (line1.point1() == line2.point1() && line1.point2() == line2.point2()) ||
                    (line1.point1() == line2.point2() && line1.point2() == line2.point1());
        }

        bool operator != (const Line2D &line1, const Line2D &line2) {
            return !(line1 == line2);
        }

        std::ostream & operator << (std::ostream & output, const Line2D &line) {
            output <<
                   "(" <<
                   "point1 = " << line.point1() << ", point2 = " << line.point2() <<
                   ")";
            return output;
        }
    }
}
