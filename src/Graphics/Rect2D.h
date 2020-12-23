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

#ifndef RPI4_STATUS_DISPLAY_GRAPHICS_RECT2D_H
#define RPI4_STATUS_DISPLAY_GRAPHICS_RECT2D_H

namespace Rpi4StatusDisplay {
    namespace Graphics {
        class Rect2D {
        protected:
            Point2D &_point;
            Size2D &_size;

        public:
            Rect2D(Point2D &point, Size2D &size);
            Rect2D(int left, int top, int width, int height);
            Point2D &point() const;
            void setPoint(Point2D &point);
            Size2D &size() const;
            void setSize(Size2D &size);
            int left() const;
            int top() const;
            int width() const;
            int height() const;
            int right() const;
            int bottom() const;
            bool contains(Point2D &point) const;

            friend bool operator == (const Rect2D &rect1, const Rect2D &rect2);
            friend bool operator != (const Rect2D &rect1, const Rect2D &rect2);
            friend std::ostream & operator << (std::ostream &output, const Rect2D &rect);
        };
    }
}

#endif //RPI4_STATUS_DISPLAY_GRAPHICS_RECT2D_H
