//
// Created by daalbano on 11/12/2020.
//
#include <iostream>
#include <string.h>

#include "Size2D.h"

#include "Framebuffer.h"

namespace Rpi4StatusDisplay {
    namespace Graphics {
        Framebuffer::Framebuffer(Size2D &size, uint8_t depth, uint32_t pitch) : _size(size) {
            this->_depth = depth;
            this->_pitch = pitch;

            // The size of the framebuffer in memory is the length of a row of pixel for the height.
            // The pitch should usually be size.width() * depth but can have some spacing at the
            // end and it will really depend on the display.
            this->_data_length = pitch * size.height();
            this->_data = new uint8_t[this->_data_length];
            memset(this->_data, 0, this->_data_length);
        }

        Framebuffer::~Framebuffer() {
            delete this->_data;
            this->_data = nullptr;
        }

        uint8_t *Framebuffer::data() const {
            return this->_data;
        }

        uint32_t Framebuffer::dataLength() const{
            return this->_data_length;
        }

        Size2D &Framebuffer::size() const {
            return this->_size;
        }

        uint32_t Framebuffer::depth() const{
            return this->_depth;
        }

        uint32_t Framebuffer::pitch() const{
            return this->_pitch;
        }

        std::ostream & operator << (std::ostream & output, const Framebuffer &f) {
            output <<
                   "(" <<
                   "size.width = " << f.size().width() << ", size.height = " << f.size().height() <<
                   ", depth = " << f.depth() << ", pitch = " << f.pitch() <<
                   ", dataLength = " << f.dataLength() << ", data = " << (void*)f.data() <<
                   ")";
            return output;
        }
    }
}
