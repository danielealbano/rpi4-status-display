//
// Created by daalbano on 11/12/2020.
//
#include <iostream>

#include "Point2D.h"
#include "Size2D.h"

#include "Rect2D.h"

namespace Rpi4StatusDisplay {
    namespace Graphics {
        Rect2D::Rect2D(int left, int top, int width, int height) {
            this->setLeft(left);
            this->setTop(top);
            this->setWidth(width);
            this->setHeight(height);
        }

        Rect2D::Rect2D(Point2D p, Size2D s) : Rect2D(p.x(), p.y(), s.width(), s.height()) {
            // do nothing
        }

        int Rect2D::left() const {
            return this->_left;
        }

        void Rect2D::setLeft(int left) {
            this->_left = left;
        }

        int Rect2D::top() const {
            return this->_top;
        }

        void Rect2D::setTop(int top) {
            this->_top = top;
        }

        int Rect2D::width() const {
            return this->_width;
        }

        void Rect2D::setWidth(int width) {
            this->_width = width;
        }

        int Rect2D::height() const {
            return this->_height;
        }

        void Rect2D::setHeight(int height) {
            this->_height = height;
        }

        int Rect2D::right() const {
            return this->_left + this->_width;
        }

        int Rect2D::bottom() const {
            return this->_top + this->_height;
        }

        bool Rect2D::contains(Point2D p) const {
            return
                p.x() >= this->left() && p.x() <= this->right() &&
                p.y() >= this->top() && p.y() <= this->bottom();
        }

        bool operator == (const Rect2D &r1, const Rect2D &r2) {
            return
                r1.left() == r2.left() &&
                r1.top() == r2.top() &&
                r1.width() == r2.width() &&
                r1.height() == r2.height();
        }

        bool operator != (const Rect2D &r1, const Rect2D &r2) {
            return !(r1 == r2);
        }

        std::ostream & operator << (std::ostream & output, const Rect2D &p) {
            output <<
                   "(" <<
                   "left = " << p.left() << ", top = " << p.top() <<
                   ", width = " << p.width() << ", height = " << p.height() <<
                   ")";
            return output;
        }
    }
}
