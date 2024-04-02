#include <stdio.h>
#ifndef FILETYPE_H_
#define FILETYPE_H_
#endif
typedef struct __attribute__ ((packed))
{
  struct __attribute__ ((packed))
  {
    unsigned short bfType;/* Magic number for file */
    unsigned int bfSize;/* Size of file */
    unsigned short bfReserved1;/* Reserved */
    unsigned short bfReserved2;
    unsigned int bfOffBits; /* Offset to bitmap data */
  } FILE_HEADER;

  struct __attribute__ ((packed)) /**** BMP file info structure ****/
  {
    unsigned int biSize;         /* Size of info header */
    int biWidth;                  /* Width of image */
    int biHeight;                 /* Height of image */
    unsigned short biPlanes;     /* Number of color planes */
    unsigned short biBitCount;   /* Number of bits per pixel */
    unsigned int biCompression;  /* Type of compression to use */
    unsigned int biSizeImage;    /* Size of image data */
    int biXPelsPerMeter;          /* X pixels per meter */
    int biYPelsPerMeter;          /* Y pixels per meter */
    unsigned int biClrUsed;      /* Number of colors used */
    unsigned int biClrImportant; /* Number of important colors */
  } INFO_HEADER;

  struct __attribute__ ((packed))/**** Colormap entry structure ****/
  {
    unsigned char rgbBlue;     /* Blue value */
    unsigned char rgbGreen;    /* Green value */
    unsigned char rgbRed;      /* Red value */
    unsigned char rgbReserved; /* Reserved */
  } RGB_QUAD;

  size_t fileHeaderSize;
  size_t fileInfoSize;
  size_t fileColorMapSize;

} BMP;

void initBMP(BMP *_BMP)
{
  _BMP->fileHeaderSize = sizeof(_BMP->FILE_HEADER);
  _BMP->fileInfoSize = sizeof(_BMP->INFO_HEADER);
  _BMP->fileColorMapSize = sizeof(_BMP->RGB_QUAD);
}