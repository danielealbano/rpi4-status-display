//
// Created by daalbano on 11/12/2020.
//

#ifndef RPI4_STATUS_DISPLAY_GRAPHICS_FRAMEBUFFER_H
#define RPI4_STATUS_DISPLAY_GRAPHICS_FRAMEBUFFER_H

namespace Rpi4StatusDisplay {
    namespace Graphics {
        class Framebuffer {
        private:
            Size2D &_size;
            uint8_t *_data;
            uint32_t _data_length;
            uint8_t _depth;
            uint32_t _pitch;

        public:
            Framebuffer(Size2D &size, uint8_t depth, uint32_t pitch);
            virtual ~Framebuffer();
            uint8_t *data() const;
            uint32_t dataLength() const;
            Size2D &size() const;
            uint32_t depth() const;
            uint32_t pitch() const;

            friend std::ostream & operator << (std::ostream &output, const Framebuffer &p);
        };
    }
}

#endif //RPI4_STATUS_DISPLAY_GRAPHICS_FRAMEBUFFER_H
