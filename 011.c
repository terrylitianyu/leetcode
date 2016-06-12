#include <stdio.h>
#include <stdlib.h>


int maxArea(int* height, int heightSize) {
  int i = 0;
  int j = heightSize - 1;
  int max = 0;
  int temp_height = 0;
  while(i < j)
  {
    temp_height = height[i] < height[j] ? height[i] * (j - (i++)) :
                                          height[j] * ((j--) - i);
    if (temp_height > max) {max = temp_height;}
  }
  return max;
}
