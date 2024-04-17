#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fileType.h"
#include "imageProcessing.h"
#include "info.h"

#define IMAGE_TYPE BMP /*define which image type we are using*/
typedef void (*FuncPtr)(unsigned char**, uint32_t, uint32_t);
typedef struct
{
  BMP *BMP;
  int32_t height;
  int32_t width;
  unsigned char **content;
  uint32_t *grayScalesQuantity;
}image;

int main()
{
  setbuf(stdout, NULL); /* disable the I/O buffer*/
  FILE *img;
  /* trying to open image*/ 
  if(!(img = fopen("./assets/Lena256.bmp", "r+b")))
  {
    printf("open fail\n");
    return 1;
  }

  image *_image = (image*) malloc(sizeof(image)); /* allocated memory for _image*/
  _image->IMAGE_TYPE= (IMAGE_TYPE*) malloc(sizeof(IMAGE_TYPE)); 

  GetData(img, (unsigned char*) _image->IMAGE_TYPE, sizeof(IMAGE_TYPE)); /* get the specify TYPE's header's data*/

  // PrintHex((unsigned char*) _image->IMAGE_TYPE, sizeof(IMAGE_TYPE));

  _image->height = _image->IMAGE_TYPE->INFO_HEADER.biHeight;
  _image->width = _image->IMAGE_TYPE->INFO_HEADER.biWidth;

  /* allocated memory for the image contents */
  _image->content= (unsigned char**) malloc(_image->height * sizeof(unsigned char*));
  for (int i = 0; i < _image->height; ++i)
    _image->content[i] = (unsigned char*) malloc(_image->width * sizeof(unsigned char));

  for (int i = 0; i < _image->height; ++i)
  {
    GetData(img, _image->content[i], _image->width);  
  }
  // for (int i = 0; i < _image->height; ++i)
  //   PrintHex(_image->data[i], _image->width);

  while(1)
  {
    FuncPtr ptr = PrintAndSelectOperations();
    unsigned char** img_data = _image->content;
    int32_t img_height = _image->height;
    int32_t img_width = _image->width;
    (*ptr)(img_data, img_height, img_width);
    printf("Do you want to continue?(y/n)");
    char ch[2];
    scanf("%s", ch, 2);
    if(ch[0] != 'y')
      break;
  } 
  /* free memory */
  for(int i = 0; i < _image->height; ++i)
    free(_image->content[i]);
  free(_image->IMAGE_TYPE);
  free(_image);
  fclose(img);
  return 0;
}