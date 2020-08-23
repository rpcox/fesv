/*
 *  execve.c - execute a program
 *
 */

#include <stdio.h>
#include <stdlib.h>     /* EXIT_FAILURE, EXIT_SUCCESS    */
#include <string.h>     /* strcmp(3)                     */
#include <unistd.h>     /* execve(2), getpid(2)          */

#define SLEEP_TIME 2

int main(int argc, char *argv[]) {
  printf("[execve] PID=%ld launched\n", (long) getpid());

  if ( argc != 2 || strcmp(argv[1], "--help") == 0 ) {
    printf("[execve] usage: %s FILE_TO_EXEC\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *execve_args[20];

  execve_args[0] = argv[1];
  execve_args[1] = "PASS_WHATEVER_YOU_WANT";
  execve_args[2] = NULL;

  char *environment[] = { "SPUD=potato", NULL };

  printf("[execve] preparing to call execve() and launch %s\n", argv[1]);

  execve(argv[1], execve_args, environment);
  printf("[execve] you shouldn't evern see this unless execve fails\n");

  exit(EXIT_SUCCESS);
}
