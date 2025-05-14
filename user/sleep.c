#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"



int main( int argc ,char *argv[])
{
  if(argc > 2)
    printf("Error: enter only one number\n");
  else if(argc < 2)
    printf("Error: must enter number of ticks\n");
  else if(strcmp(argv[1], "?")==0)
  {
    printf("Usage: sleep ticks\n");
  }
  else
  {
    int time = atoi(argv[1]);
    if(time == 0)
      printf("Error: invalid input\n");
    else
    {
      printf("sleeping For %d\n",time);
      sleep(time);
    }
  }
  exit(0);

}
