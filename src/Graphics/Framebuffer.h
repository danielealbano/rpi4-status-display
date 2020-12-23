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

#ifndef RPI4_STATUS_DISPLAY_GRAPHICS_FRAMEBUFFER_H
#define RPI4_STATUS_DISPLAY_GRAPHICS_FRAMEBUFFER_H

// TODO: the framebuffer should be refactored to implement a set of different classes per Depth and to properly
//       support a palette in case of indexed colors

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
