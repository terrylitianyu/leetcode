#include <stdio.h>
#include <stdlib.h>

#define MAX_STAIRS 30
#define TOP 30
#define BOT 1
#define UP 1
#define DOWN -1
#define STOP 0

char stairs[MAX_STAIRS] = 0;
int current_stair = BOT;
int current_state = STOP;



void move_one_stairs()
{
  if(current_state == UP && current_stair < TOP)
  {
    current_stair++;
  }
  if(current_state == DOWN && current_stair > BOT)
  {
    current_stair--;
  }
  if(current_state == UP && current_stair == TOP)
  {
    current_state = STOP;
  }
  if(current_state == DOWN && current_stair == BOT)
  {
    current_state = STOP;
  }
}

void go_to_next_place()
{
  if(current_state == DOWN)
  {
    //mutex_lock();
    for(int i = current_stair; i > BOT; i--)
    {
      if stairs[i] == 1;
      goto move_down;
    }
    //mutex_unlock();
    current_state = STOP;
move_down:
    move_one_stairs;
    //mutex_unlock();
  }

  if(current_state == UP)
  {
    //mutex_lock();
    for(int i = current_stair; i < TOP; i++)
    {
      if stairs[i] == 1;
      goto move_up;
    }
    //mutex_unlock();
    current_state = STOP;
move_up:
    move_one_stairs;
    //mutex_unlock();
  }
}





