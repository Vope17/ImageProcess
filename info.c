#include "info.h"
#include "imageProcessing.h"
#include <stdint.h>
#include <stdio.h>
typedef void (*FuncPtr)(unsigned char**, uint32_t, uint32_t);
FuncPtr PrintAndSelectOperations()
{
  int choice;
  printf("Choose what you want to do\n");
  printf("1.Filter\n");
  printf("2.\n");
  printf("3.\n");
  scanf("%d", &choice); 
  return SelectOperations(choice);
}
FuncPtr SelectOperations(uint8_t choice)
{
  switch (choice)
  {
    case 1:
      return PrintFilters();
  }  
}
FuncPtr PrintFilters()
{
  int choice;
  printf("1.GaussianFilter\n");
  printf("2.Average Filter\n");
  printf("3.Prewitt Filter\n");
  printf("4.Sobel Filter\n");
  printf("5.Robert Filter\n");
  printf("6.Laplacian Filter\n");
  printf("7.HighPass Filter\n");
  printf("8.LowPass Filter\n");
  printf("9.Sharpening Filter\n");
  scanf("%d", &choice);
  return Filters(choice);
}

FuncPtr Filters(uint8_t choice)
{
  void (* p)(unsigned char**, uint32_t, uint32_t);
  switch(choice) 
  {
    case 1:
      return &GaussianFilter;
    case 2:
      return &AverageFilter;
    case 3:
      return &PrewittFilter;
    case 4:
      return &SobelFilter;
    case 5:
      return &RobertFilter;
    case 6:
      return &LaplacianFilter;
    case 7:
      return &HighPassFilter;
    case 8:
      return &LowPassFilter;
    case 9:
      return &SharpeningFilter;
  }
}