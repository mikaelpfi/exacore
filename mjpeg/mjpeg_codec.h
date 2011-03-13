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
#ifndef _OPENREPLAY_MJPEG_CODEC_H
#define _OPENREPLAY_MJPEG_CODEC_H

#include "types.h"
#include "jpeglib.h"

class Mjpeg422Encoder {
    public:
        Mjpeg422Encoder(coord_t w_, coord_t h_, 
                size_t max_frame_size = 524288);
        void encode(RawFrame *f);
        void *get_data(void);
        size_t get_data_size(void);
        ~Mjpeg422Encoder( );
    protected:
        void libjpeg_init( );

        coord_t w, h;
        uint8_t *y_plane, *cb_plane, *cr_plane;
        uint8_t *jpeg_data;
        size_t jpeg_alloc_size, jpeg_finished_size;

        struct jpeg_compress_struct cinfo;
        struct jpeg_error_mgr jerr;
};

#endif