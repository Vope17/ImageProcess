#include <stdint.h>
#include "imageProcessing.h"
#include "filters.h"
int GetData(FILE *img, unsigned char *buffer, uint32_t _size)
{
  if (fread(buffer, 1, _size, img) != _size)
  {
    printf("error at: GetData()\n");
    fclose(img);
    return 1;
  }
  return 0;
}

void PrintHex(unsigned char *data, uint32_t _size)
{
  for (int i = 0; i < _size; ++i)
    printf("%.2x ", data[i]);

  printf("\n");
}

void Quantization(unsigned char *data, uint32_t dataSize, uint32_t *Counting)
{
  for(int i = 0; i < dataSize; ++i)
    Counting[data[i]]++;
}

void GaussianFilter(unsigned char** data, uint32_t height, uint32_t width)
{
  printf("doing Gaus\n");
}

void AverageFilter(unsigned char** data, uint32_t height, uint32_t width)
{
  printf("doing Ave\n");
}

void PrewittFilter(unsigned char** data, uint32_t height, uint32_t width)
{
  printf("doing Pre\n");
}

void SobelFilter(unsigned char** data, uint32_t height, uint32_t width)
{
  printf("doing Sobel\n");
}

void RobertFilter(unsigned char** data, uint32_t height, uint32_t width)
{
  printf("doing Rober\n");
}

void LaplacianFilter(unsigned char** data, uint32_t height, uint32_t width)
{
  printf("doing Lapl\n");
}

void HighPassFilter(unsigned char** data, uint32_t height, uint32_t width)
{
  printf("doing Highpass\n");
}

void LowPassFilter(unsigned char** data, uint32_t height, uint32_t width)
{
  printf("doing Lowpass\n");
}

void SharpeningFilter(unsigned char** data, uint32_t height, uint32_t width)
{
  printf("doing Shapren\n");
}
