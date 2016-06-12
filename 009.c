/**
 * @file 009.c
 */

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
      return 0;
    }
    if ((rtn == 214748364 && k > 7) ||
        (rtn == -214748364 && k < -8))
    {
      return 0;
    }
    rtn = rtn * 10 + k % 10;
    k = k / 10;
    i--;
  }
  return rtn;
}

bool isPalindrome(int x) {
  if (x < 0) return false;
  return x == reverse(x);
}
