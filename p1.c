#include <stdio.h>
int main(void)
{
  int test_n = 0;
  int N = 0;
  int P = 0;
  int W = 0;
  int H = 0;
  int paragraph_list[1000];
  int i = 0;
  int j = 0;
  int f = 0;
  int n_row = 0;
  int n_col = 0;
  int sum = 0;
  scanf("%d", &test_n);
  int output_list[test_n];
  for (i = 0; i < test_n; i++)
  {
    scanf("%d %d %d %d", &N, &P, &W, &H);
    for (j = 0; j < N; j++)
    {
      scanf("%d", &paragraph_list[j]);
    }
    for (f = 1; f <= W && f <= H; f++)
    {
      n_row = W/f;
      n_col = H/f;
      sum = 0;
      for (j = 0; j < N; j++)
      {
        sum += paragraph_list[j] / n_row + !!(paragraph_list[j] % n_row);
      }
      if ((sum / n_col + !!(sum % n_col)) > P)
      {
        output_list[i] = f - 1;
        break;
      }
      if (f >= W || f >= H)
      {
        output_list[i] = f;
      }
    }
  }
  for (i = 0; i < test_n; i++)
  {
    printf("%d\n", output_list[i]);
  }
  return 0;
}
