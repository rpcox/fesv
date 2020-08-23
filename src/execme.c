/*
 *  execme.c - something for execve to do
 *
 */

#include <stdio.h>
#include <stdlib.h>     /* EXIT_FAILURE, EXIT_SUCCESS    */
#include <unistd.h>     /* execve(2), getpid(2)          */

extern char **environ;

int main(int argc, char *argv[]) {
  printf("[execme] PID=%ld launched\n", (long) getpid());

  if ( argc > 2 )
  {
    printf("[execme] no arguments passed on command line\n");
  }
  else
  {
    printf("[execme] argument passed is \"%s\"\n", argv[1]);
  }

  printf("[execme] environ passed to exec_me : \"%s\"\n", *environ);
  fflush(stdout);

  printf("[execme] exiting ...\n");
  exit(EXIT_SUCCESS);
}
