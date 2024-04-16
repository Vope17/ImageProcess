#include <stdint.h>
#include "imageProcessing.h"
#include "filters.h"
int GetData(FILE *img, unsigned char buffer[], size_t _size)
{
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

void GaussianFilter(unsigned char** data, int32_t height)
{

}

void AverageFilter()
{

}

void PrewittFilter()
{

}

void SobelFilter()
{

}

void RobertFilter()
{

}

void LaplacianFilter()
{

}

void HighPassFilter()
{

}

void LowPassFilter()
{

}

void SharpeningFilter()
{

}
