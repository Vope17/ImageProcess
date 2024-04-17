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
      // GaussianFilter(img_data, img_height, img_width);
    case 2:
      return &AverageFilter;
      // AverageFilter(img_data, img_height, img_width);
    case 3:
      return &PrewittFilter;
      // PrewittFilter(img_data, img_height, img_width);
    case 4:
      return &SobelFilter;
      // SobelFilter(img_data, img_height, img_width);
    case 5:
      return &RobertFilter;
      // RobertFilter(img_data, img_height, img_width);
    case 6:
      return &LaplacianFilter;
      // LaplacianFilter(img_data, img_height, img_width);
    case 7:
      return &HighPassFilter;
      // HighPassFilter(img_data, img_height, img_width);
    case 8:
      return &LowPassFilter;
      // LowPassFilter(img_data, img_height, img_width);
    case 9:
      return &SharpeningFilter;
      // SharpeningFilter(img_data, img_height, img_width);
  }
}