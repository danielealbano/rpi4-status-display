//
// Created by daalbano on 11/12/2020.
//
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
