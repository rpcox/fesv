/*
 *  system.c - execute some shell commands
 *
 */

#include <stdio.h>
#include <stdlib.h>     /* EXIT_FAILURE, EXIT_SUCCESS, system(3) */
#include <unistd.h>     /* fork(2), getpid(2), sleep(3)          */

int main() {
  int my_exit = EXIT_SUCCESS;
  printf("[system] PID=%ld launched\n", (long) getpid());

  /* The list of shell commands to execute */
  char *command_list[] = { "echo $SHELL",
                           "pwd",
                           "ls /",
                           "touch /tmp/system_file",
                           "ls -l /tmp/system_file",
                           "spud", /* execute non-existing file */
                           NULL };

  for ( int i = 0; command_list[i] != NULL; i++) {
    printf("\n[%d] command: %s\n\n", i+1, command_list[i]);
    int ret_val = system(command_list[i]);
    printf("\n[%d] system() returned: 0x%04x\n", i+1, ret_val);

    if ( ret_val == -1 ) {
      printf("** could not create child\n");
      my_exit = EXIT_FAILURE;
    }
    else if ( ret_val == 0 ) {
      printf(" success\n");

      if ( WIFEXITED(ret_val) )
        printf(" child exited, status = %d\n", WEXITSTATUS(ret_val) );
    }
    else if ( WIFEXITED(ret_val) && WEXITSTATUS(ret_val) == 0x7F ) {
      printf(" command or shell not available\n");
      my_exit = EXIT_FAILURE;
    }
    else {
      printf("possible core dump, SIGCHLD, stopped job, or other thing not covered here\n");
      my_exit = EXIT_FAILURE;
    }

    sleep(2);
  }

  printf("\n[system] PID=%ld exiting\n", (long) getpid());
  exit(my_exit);
}
