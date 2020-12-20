//
// Created by daalbano on 11/12/2020.
//

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
