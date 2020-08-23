/*
 *  fork.c - create a child process
 *
 */

#include <sys/types.h>  /* pid_t                         */
#include <stdio.h>
#include <stdlib.h>     /* EXIT_FAILURE, EXIT_SUCCESS    */
#include <unistd.h>     /* fork(2), getpid(2), sleep(3)  */

#define SLEEP_TIME 3

/* 'data_seg_int', will be placed in the data segment.   */

static int data_seg_int = 1;

int main() {
  /* 'stack_int_seg' will be placed in the stack segment. */
  int stack_seg_int = 2;
  pid_t pid;

  printf("[parent] PID=%ld   stack_seg_int = %d    data_seg_int = %d%s",
           (long) getpid(), stack_seg_int, data_seg_int, "\n");
  fflush(stdout);

  /*  The call to fork(2) below will return 1 of 3 values.
   *    -1 => the fork failed
   *     0 => the fork return value for the child,
   *     N => the fork return value for the parent (PID of the child)
   */

  switch ( pid = fork() ) {

    case -1:                    /* Something went wrong                    */
      printf("fork failed\n");  /* The failed parent will now quietly die. */
      exit(EXIT_FAILURE);

    case 0:                     /* pid = 0                                 */
      data_seg_int  *= 10;      /* child multiplies the variables by 10    */
      stack_seg_int *= 10;
      printf(" [child] PID=%ld   going to sleep\n", (long) getpid() );
      sleep(SLEEP_TIME);
      break;

    default:                    /* pid = N                                 */
      data_seg_int  *= 20;      /* parent multiplies the variables by 20   */
      stack_seg_int *= 20;
      printf("[parent] PID=%ld   going to sleep\n", (long) getpid() );
      sleep(SLEEP_TIME + 1 );
      break;
  }


  if ( pid ) {                 /* pid != 0, this is the parent */
    printf( "%s", "[parent]");
  }
  else {
    printf( "%s", " [child]");
  }

  printf(" PID=%ld   stack_seg_int = %d   data_seg_int = %d%s",
           (long) getpid(), stack_seg_int, data_seg_int, "   exiting\n");

  fflush(stdout);
  exit(EXIT_SUCCESS);
}
