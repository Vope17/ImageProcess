#ifndef IMAGE_PROCESSING_H_
#define IMAGE_PROCESSING_H_
#endif

#include <stdio.h>
#include <stdlib.h>
int GetData(FILE *img, unsigned char* buffer, uint32_t _size);
void PrintHex(unsigned char* data, uint32_t _size);
void Quantization(unsigned char* data, uint32_t dataSize, uint32_t *Counting);
void GaussianFilter(unsigned char** data, uint32_t height, uint32_t width);
void AverageFilter(unsigned char** data, uint32_t height, uint32_t width);
void PrewittFilter(unsigned char** data, uint32_t height, uint32_t width);
void SobelFilter(unsigned char** data, uint32_t height, uint32_t width);
void RobertFilter(unsigned char** data, uint32_t height, uint32_t width);
void LaplacianFilter(unsigned char** data, uint32_t height, uint32_t width);
void HighPassFilter(unsigned char** data, uint32_t height, uint32_t width);
void LowPassFilter(unsigned char** data, uint32_t height, uint32_t width);
void SharpeningFilter(unsigned char** data, uint32_t height, uint32_t width);
