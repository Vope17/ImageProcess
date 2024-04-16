#include <stdio.h>
#include <stdlib.h>
int GetData(FILE *img, unsigned char buffer[], size_t _size);
void printHex(unsigned char data[], size_t _size);
void Quantization(unsigned char data[], size_t dataSize, unsigned int Counting[]);
