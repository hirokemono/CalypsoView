
/* write_image_2_png.h */

#ifndef WRITE_IMAGE_2_PNG_
#define WRITE_IMAGE_2_PNG_

#include <stdio.h>
#include <stdlib.h>

#ifndef DEPENDENCY_CHECK
  #include <zlib.h>
  #include <png.h>
#endif

#include "calypso_param_c.h"

/* prototypes */


void write_png_rgba(const char *file_name, png_uint_32 num_x, png_uint_32 num_y,
			png_bytepp image);
void write_png_rgb(const char *file_name, png_uint_32 num_x, png_uint_32 num_y,
			png_bytepp image);

void write_png_rgba_c(const char *file_head, const int *num_x, const int *num_y, const char *cimage);
void write_png_rgb_c(const char *file_head, const int *num_x, const int *num_y, const char *cimage);

/*    file_name:     output file_name
 num_x, num_y:  size of image (pixels)
 image:         image array
 (unsigned char, 4*num_x*num_y for RGBA, 3*num_x*num_y for RGB) */

#endif

