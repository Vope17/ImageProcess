#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fileType.h"
#include "imageProcessing.h"

#define TYPE _BMP

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

  /* 獲得相對應TYPE的headers的pointer*/
  unsigned char *fileHeader = (unsigned char*)&(TYPE->FILE_HEADER);
  unsigned char *infoHeader = (unsigned char*)&(TYPE->INFO_HEADER);
  unsigned char *colorMap = (unsigned char*)&(TYPE->RGB_QUAD);
  size_t fileHeaderSize = TYPE->fileHeaderSize;
  size_t fileInfoSize = TYPE->fileInfoSize;
  size_t fileColorMapSize = TYPE->fileColorMapSize;

  /* 獲得相對應TYPE的headers的data */
  if(GetData(img, fileHeader, fileHeaderSize))
    return 1;
  if(GetData(img, infoHeader, fileHeaderSize))
    return 1;
  if(GetData(img, colorMap, fileHeaderSize))
    return 1;

  /* 動態分配記憶體 */
  size_t typeHeight = TYPE->INFO_HEADER.biHeight;
  size_t typeWidth = TYPE->INFO_HEADER.biWidth;
  unsigned char **data = (unsigned char**)malloc(typeHeight * sizeof(unsigned char*));
  for(int i = 0; i < typeHeight; ++i)
    data[i] = (unsigned char*)malloc(typeWidth * sizeof(unsigned char));


  for(int i = 0; i < typeHeight; ++i)
    GetData(img, data[i], typeWidth);  
  for(int i = 0; i < typeHeight; ++i)
    printHex(data[i], typeWidth); 


  /* free memory */
  for(int i = 0; i < typeHeight; ++i)
    free(data[i]);
  free(data);
  free(_BMP);
  fclose(img);
  return 0;
}