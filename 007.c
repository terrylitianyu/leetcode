#include <stdio.h>
#include <stdlib.h>

int reverse(int x)
{
  int k = x;
  int rtn = 0;
  int i = 0;
  while (k != 0)
  {
    i++;
    k = k / 10;
  }

  k = x;
  while (i != 0)
  {
    if (rtn > 214748364 || rtn < -214748364)
    {
      printf("%d, 1\n", i);
      printf("%d\n", rtn);
      return 0;
    }
    if ((rtn == 214748364 && k > 7) ||
        (rtn == -214748364 && k < -8))
    {
      printf("2\n");
      return 0;
    }
    rtn = rtn * 10 + k % 10;
    k = k / 10;
    i--;
  }
  return rtn;
}

int main(int argc, char** argv)
{
  int x = 1534236469;
  int y = -123;
  int a = reverse(x);
  int b = reverse(y);
  printf("%d, %d", -(0x80000000 / 10), b);
}
