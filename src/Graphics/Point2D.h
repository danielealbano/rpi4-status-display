//
// Created by daalbano on 11/12/2020.
//

#ifndef RPI4_STATUS_DISPLAY_GRAPHICS_POINT2D_H
#define RPI4_STATUS_DISPLAY_GRAPHICS_POINT2D_H

namespace Rpi4StatusDisplay {
    namespace Graphics {
        class Point2D {
        protected:
            int _x;
            int _y;

        public:
            Point2D(int x, int y);
            int x() const;
            void setX(int x);
            int y() const;
            void setY(int x);

            friend std::ostream & operator << (std::ostream &output, const Point2D &p);

            friend bool operator == (const Point2D &p1, const Point2D &p2);
            friend bool operator != (const Point2D &p1, const Point2D &p2);
        };
    }
}

#endif //RPI4_STATUS_DISPLAY_GRAPHICS_POINT2D_H
