#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int global_H[10100] = {10100};
int M = 0;
int N = 0;

int help(char** input_maze)
{
  int i = 0;
  int j = 0;
  int flag_list[10000];
  int counter = 0;

  while (i < M && j < N)
  {
    for(; j < N - 1; j++)
    {
      if (input_maze[i][j + 1] == 1)
      {
        flag_list[counter] = i*M+j;
        counter++;
        break;
      }
    }
    if (i == M - 1)
    {
      break;
    }
    for(; i < M - 1; i++)
    {
      if (input_maze[i + 1][j] == 1)
      {
        flag_list[counter] = i*M+j;
        counter++;
        break;
      }
    }
    if (j == N - 1)
    {
      break;
    }
    if (input_maze[i+1][j] == 1 && input_maze[i][j+1] == 1)
    {
      break;
    }
  }

  for (i = 0; i < 10000; i++)
  {
    if (flag_list[i] == 1)
    {
      printf("%d\n", i);
    }
  }
  return;
}


int main(void)
{
  int i = 0;
  int j = 0;
  scanf("%d %d", &M, &N);
  int rtn = 0;
  char** maze  = malloc(sizeof(char*)*(M+2));
  for (i = 0; i< M; i++)
  {
    maze[i] = malloc(sizeof(char)*(N+2));
  }
  for(i = 0; i < M; i++)
  {
    scanf("%s", &maze[i]);
    for (j = 0; j < N; j++)
    {
      if(maze[i][j] == '.')
      {
        maze[i][j] = 0;
      }
      if(maze[i][j] == 'b')
      {
        maze[i][j] = 1;
      }
    }
  }
  if (maze[0][0] == 1)
  {
    rtn += 1;
    maze[0][0] = 0;
  }
  if (maze[M-1][N-1] == 1)
  {
    rtn += 1;
    maze[M-1][N-1] = 0;
  }

  help(maze);


  return 0;
}
