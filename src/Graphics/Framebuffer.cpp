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
            delete[] this->_data;
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
