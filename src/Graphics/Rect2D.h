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
            int _top;
            int _left;
            int _width;
            int _height;

        public:
            Rect2D(int x, int y, int width, int height);
            Rect2D(Point2D p, Size2D s);
            int left() const;
            void setLeft(int left);
            int top() const;
            void setTop(int top);
            int width() const;
            void setWidth(int width);
            int height() const;
            void setHeight(int height);
            int right() const;
            int bottom() const;
            bool contains(Point2D p) const;

            friend bool operator == (const Rect2D &p1, const Rect2D &p2);
            friend bool operator != (const Rect2D &p1, const Rect2D &p2);
            friend std::ostream & operator << (std::ostream &output, const Rect2D &p);
        };
    }
}

#endif //RPI4_STATUS_DISPLAY_GRAPHICS_RECT2D_H
