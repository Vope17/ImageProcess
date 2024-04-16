#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fileType.h"
#include "imageProcessing.h"

#define TYPE _BMP
typedef struct image 
{
  unsigned char *fileHeader;
  unsigned char *infoHeader;
  unsigned char *colorMap;
  uint16_t fileHeaderSize;
  uint16_t fileInfoSize;
  uint16_t fileColorMapSize;
  int32_t height;
  int32_t width;
  unsigned char **data;
}image;


int main()
{
  FILE *img;
  BMP *_BMP = (BMP*)malloc(sizeof(BMP));  
  initBMP(_BMP);
  
  if(!(img = fopen("./assets/Lena256.bmp", "r+b")))
  {
    printf("open fail\n");
    return 1;
  }

  image *_image = (image*) malloc(sizeof(image));
  /* 獲得相對應TYPE的headers的pointer*/
  _image->fileHeader = (unsigned char*)&(TYPE->FILE_HEADER);
  _image->infoHeader = (unsigned char*)&(TYPE->INFO_HEADER);
  _image->colorMap = (unsigned char*)&(TYPE->RGB_QUAD);

  _image->fileHeaderSize = TYPE->fileHeaderSize;
  _image->fileInfoSize = TYPE->fileInfoSize;
  _image->fileColorMapSize = TYPE->fileColorMapSize;

  /* 獲得相對應TYPE的headers的data */
  if(GetData(img, _image->fileHeader, _image->fileHeaderSize))
    return 1;
  if(GetData(img, _image->infoHeader, _image->fileHeaderSize))
    return 1;
  if(GetData(img, _image->colorMap, _image->fileHeaderSize))
    return 1;

  _image->height = TYPE->INFO_HEADER.biHeight;
  _image->width = TYPE->INFO_HEADER.biWidth;
  _image->data = (unsigned char**)malloc(_image->height * sizeof(unsigned char*));
  /* 動態分配記憶體 */
  for(int i = 0; i < _image->height; ++i)
    _image->data[i] = (unsigned char*)malloc(_image->width * sizeof(unsigned char));

  for(int i = 0; i < _image->height; ++i)
    GetData(img, _image->data[i], _image->width);  

  for(int i = 0; i < _image->height; ++i)
    printHex(_image->data[i], _image->width); 

  /* free memory */
  for(int i = 0; i < _image->height; ++i)
    free(_image->data[i]);
  free(_image);
  free(_BMP);
  fclose(img);
  return 0;
}