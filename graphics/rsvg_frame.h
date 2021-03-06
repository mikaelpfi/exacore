/*
 * Copyright 2011 Andrew H. Armenia.
 * 
 * This file is part of openreplay.
 * 
 * openreplay is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * openreplay is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with openreplay.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _OPENREPLAY_RSVG_FRAME_H
#define _OPENREPLAY_RSVG_FRAME_H

#include "cairo_frame.h"

class RsvgFrame : public CairoFrame {
    private:
        RsvgFrame() : CairoFrame(0, 0) { /* never construct RsvgFrames */  }

    public:
        static RawFrame *render_svg(const char *svg_data, size_t size);
};

#endif
