#ifndef FILETYPE_H_
#define FILETYPE_H_
#endif

#include <stdio.h>
#include <stdint.h>
typedef struct __attribute__ ((packed)) /* 58 bytes */
{
  struct __attribute__ ((packed))
  {
    uint16_t bfType;/* Magic number for file 2 bytes*/ 
    uint32_t bfSize;/* Size of file 4 bytes*/
    uint16_t bfReserved1;/* Reserved 2 bytes*/
    uint16_t bfReserved2; /* 2 bytes*/
    uint32_t bfOffBits; /* Offset to bitmap data 4 bytes*/
  } FILE_HEADER;

  struct __attribute__ ((packed)) /**** BMP file info structure ****/
  {
    uint32_t biSize;         /* Size of info header 4 bytes*/
    int32_t biWidth;                  /* Width of image 4 bytes*/
    int32_t biHeight;                 /* Height of image 4 bytes*/
    uint16_t biPlanes;     /* Number of color planes 2 bytes*/
    uint16_t biBitCount;   /* Number of bits per pixel 2 bytes*/
    uint32_t biCompression;  /* Type of compression to use 4 bytes*/
    int32_t biSizeImage;    /* Size of image data 4 bytes*/
    int32_t biXPelsPerMeter;          /* X pixels per meter 4 bytes*/
    int32_t biYPelsPerMeter;          /* Y pixels per meter 4 bytes*/
    uint32_t biClrUsed;      /* Number of colors used 4 bytes*/
    uint32_t biClrImportant; /* Number of important colors 4 bytes*/
  } INFO_HEADER;

  struct __attribute__ ((packed))/**** Colormap entry structure ****/
  {
    unsigned char rgbBlue;     /* Blue value 1 bytes*/
    unsigned char rgbGreen;    /* Green value 1 bytes*/
    unsigned char rgbRed;      /* Red value 1 bytes*/
    unsigned char rgbReserved; /* Reserved 1 bytes*/
  } RGB_QUAD;

} BMP;
