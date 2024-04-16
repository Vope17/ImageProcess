#include <stdint.h>
#include <stdio.h>

void func(int data[], int _size)
{
  for (int i = 0; i < _size; ++i)
    printf("%d ", data[i]);
}
int main()
{
  int data[5][5] = {0};
  func((int *)data, 25);
  // int **data = (int **) malloc(5 * sizeof(int *));

  return 0;
}

