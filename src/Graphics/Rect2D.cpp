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
#include <memory>

#include "Point2D.h"
#include "Size2D.h"

#include "Rect2D.h"

namespace Rpi4StatusDisplay {
    namespace Graphics {
        Rect2D::Rect2D(Point2D &point, Size2D &size) : _point(point), _size(size) {
        }

        Rect2D::Rect2D(int left, int top, int width, int height) : Rect2D(
                *std::make_shared<Point2D>(left, top),
                *std::make_shared<Size2D>(width, height)) {
        }

        Point2D &Rect2D::point() const {
            return this->_point;
        }

        void Rect2D::setPoint(Point2D &point) {
            this->_point = point;
        }

        Size2D &Rect2D::size() const {
            return this->_size;
        }

        void Rect2D::setSize(Size2D &size) {
            this->_size = size;
        }

        int Rect2D::left() const {
            return this->point().left();
        }

        int Rect2D::top() const {
            return this->point().top();
        }

        int Rect2D::width() const {
            return this->size().width();
        }

        int Rect2D::height() const {
            return this->size().height();
        }

        int Rect2D::right() const {
            return this->point().left() + this->size().width();
        }

        int Rect2D::bottom() const {
            return this->point().top() + this->size().height();
        }

        bool Rect2D::contains(Point2D &point) const {
            return
                    point.left() >= this->left() && point.left() <= this->right() &&
                    point.top() >= this->top() && point.top() <= this->bottom();
        }

        bool operator == (const Rect2D &rect1, const Rect2D &rect2) {
            return
                    rect1.point() == rect2.point() &&
                    rect1.size() == rect2.size();
        }

        bool operator != (const Rect2D &rect1, const Rect2D &rect2) {
            return !(rect1 == rect2);
        }

        std::ostream & operator << (std::ostream & output, const Rect2D &rect) {
            output <<
                   "(" <<
                   "left = " << rect.left() << ", top = " << rect.top() <<
                   ", width = " << rect.width() << ", height = " << rect.height() <<
                   ")";
            return output;
        }
    }
}
