//
// Created by daalbano on 11/12/2020.
//

#ifndef RPI4_STATUS_DISPLAY_GRAPHICS_SIZE2D_H
#define RPI4_STATUS_DISPLAY_GRAPHICS_SIZE2D_H

namespace Rpi4StatusDisplay {
    namespace Graphics {
        class Size2D {
        protected:
            int _width;
            int _height;

        public:
            Size2D(int width, int height);
            int width() const;
            void setWidth(int width);
            int height() const;
            void setHeight(int height);

            friend std::ostream & operator << (std::ostream &output, const Size2D &p);

            friend bool operator == (const Size2D &p1, const Size2D &p2);
            friend bool operator != (const Size2D &p1, const Size2D &p2);
        };
    }
}

#endif //RPI4_STATUS_DISPLAY_GRAPHICS_SIZE2D_H
