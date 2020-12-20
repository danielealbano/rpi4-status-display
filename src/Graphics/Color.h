//
// Created by daalbano on 11/12/2020.
//

#ifndef RPI4_STATUS_DISPLAY_GRAPHICS_COLOR_H
#define RPI4_STATUS_DISPLAY_GRAPHICS_COLOR_H

namespace Rpi4StatusDisplay {
    namespace Graphics {
        class Color {
        protected:
            uint8_t _red;
            uint8_t _green;
            uint8_t _blue;
            uint8_t _alpha;

        public:
            Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
            uint8_t red() const;
            void setRed(uint8_t red);
            uint8_t green() const;
            void setGreen(uint8_t green);
            uint8_t blue() const;
            void setBlue(uint8_t blue);
            uint8_t alpha() const;
            void setAlpha(uint8_t alpha);

            friend std::ostream & operator << (std::ostream &output, const Color &p);

            friend bool operator == (const Color &p1, const Color &p2);
            friend bool operator != (const Color &p1, const Color &p2);

            /**
             * Predefined colors
             */
            static const Color White;
            static const Color Black;
        };
    }
}

#endif //RPI4_STATUS_DISPLAY_GRAPHICS_COLOR_H
