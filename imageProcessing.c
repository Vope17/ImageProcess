#include "imageProcessing.h"

int GetData(FILE *img, unsigned char buffer[], size_t _size)
{
  int ch;
  if (fread(buffer, 1, _size, img) != _size)
  {
    printf("error at: GetData()\n");
    fclose(img);
    return 1;
  }
  return 0;
}

void printHex(unsigned char data[], size_t _size)
{
  for (int i = 0; i < _size; ++i)
    printf("%.2x ", data[i]);

  printf("\n");
}

void Quantization(unsigned char data[], size_t dataSize, unsigned int Counting[])
{
  for(int i = 0; i < dataSize; ++i)
    Counting[data[i]]++;
}
