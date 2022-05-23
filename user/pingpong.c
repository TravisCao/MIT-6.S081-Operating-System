#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char buf[1];

int
main(int argc, char *argv[])
{
  // create pipe
  // fork to create a child
  // read & write
  // getpid - get pid
  int p[2];
  pipe(p);
  if (fork() == 0) {
    read(p[0], buf, 1); 
    close(p[0]);
    fprintf(1, "%d: received ping\n", getpid());
    write(p[1], buf, 1);
    close(p[1]);
    exit(0);
  } else {
    write(p[1], " ", 1);
    close(p[1]);
    wait(0);
    read(p[0], buf, 1); 
    close(p[0]);
    fprintf(1, "%d: received pong\n", getpid());
    exit(0);
  }
}
