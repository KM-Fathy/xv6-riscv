#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"


int main( int argc ,char *argv[])
{
  //add to Makefile
  if(strcmp(argv[1], "?") == 0) {
    printf("Usage: mv source_path destination_path\n");
    exit(0);
  }
}
