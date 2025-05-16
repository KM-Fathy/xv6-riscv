#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"


int main(int argc, char *argv[]) {

  int pid;
  int k, nprocess = 10;
  int z, steps = 1000000;
  char buffer_src[1024], buffer_dst[1024];
  int total_ta=0, total_w=0;


  for (k = 0; k < nprocess; k++) {
    // ensure different creation times (proc->ctime)
    // needed for properly testing FCFS scheduling
    sleep(2);


    pid = fork();
    if (pid < 0) {
      printf("%d failed in fork!\n", getpid());
      exit(0);

    }
    else if (pid == 0) {
      // child
      printf("[pid=%d] created\n", getpid());

      for (z = 0; z < steps; z += 1) {
         // copy buffers one inside the other and back
         // used for wasting cpu time
         memmove(buffer_dst, buffer_src, 1024);
         memmove(buffer_src, buffer_dst, 1024);
      }
      exit(0);
    }
  }

  for (k = 0; k < nprocess; k++) {
    int tatime, wtime;
    pid = waitx(0, &tatime, &wtime);
    total_ta += tatime;
    total_w += wtime;
    printf("[pid=%d] terminated   TA=%d   W=%d\n", pid, tatime, wtime);
  }

  int avg_ta = total_ta/nprocess;
  int avg_w = total_w/nprocess; //total_w/(float)nprocess
  printf("Avg turnaround time = %d,  Avg waiting time = %d\n", avg_ta, avg_w);

  exit(0);
}
