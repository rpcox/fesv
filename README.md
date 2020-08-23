## fork-exec-system

#### Make the executables
    $  make

#### Usage

    $ execve execme
    $ fork
    $ system
    $ vfork

### execve()

Execute a program.  The program must be either a binary executable or a script with the appropriate shebang.  On success, the originating binary (execve) is 'gutted' and never returns.  The program (execme) is loaded, launched and assumes execve's process ID and address/memory space.

.

    $ src/execve src/execme
    [execve] PID=21487 launched
    [execve] preparing to call execve() and launch src/execme
    [execme] PID=21487 launched
    [execme] argument passed is "PASS_WHAT_YOU_WANT"
    [execme] environ passed to execme : SPUD=potato
    [execme] exiting ...
    $

### fork()

Create a child process.  The parent forks a child, the child receives it's own process ID and a copy of all of the parent's data .  Parent and child both continue in operation.

.

    $ src/fork
    [parent] PID=21369   stack_seg_int = 2    data_seg_int = 1
    [parent] PID=21369   going to sleep
     [child] PID=21370   going to sleep
     [child] PID=21370   stack_seg_int = 20   data_seg_int = 10   exiting
    [parent] PID=21369   stack_seg_int = 40   data_seg_int = 20   exiting
    $

### vfork()

Create a child process and block the parent.  The parent forks a child, but is blocked until child returns.

.

    $ src/vfork
    [parent] PID=21420   stack_seg_int = 2    data_seg_int = 1
     [child] PID=21421   going to sleep
     [child] PID=21421   stack_seg_int = 20   data_seg_int = 10   exiting
    [parent] PID=21420   going to sleep
    [parent] PID=21420   stack_seg_int = 400   data_seg_int = 200   exiting

### system()

Execute a shell command ( or a series of them )

.

    $ src/system
    [system] PID=15481 launched

    [1] command: echo $SHELL

    /bin/bash

    [1] system() returned: 0x0000
    success
    child exited, status = 0

    [2] command: pwd

    /project/fesv/src

    [2] system() returned: 0x0000
    success
    child exited, status = 0

    [3] command: ls /

    bin    data  home        lib64       mnt   root  snap  tmp  vmlinuz
    boot   dev   initrd.img  lost+found  opt   run   srv   usr
    cdrom  etc   lib         media       proc  sbin  sys   var

    [3] system() returned: 0x0000
    success
    child exited, status = 0

    [4] command: touch /tmp/system_file


    [4] system() returned: 0x0000
    success
    child exited, status = 0

    [5] command: ls -l /tmp/system_file

    -rw-r--r-- 1 ric ric 0 Aug 22 22:00 /tmp/system_file

    [5] system() returned: 0x0000
    success
    child exited, status = 0

    [6] command: spud

    sh: 1: spud: not found

    [6] system() returned: 0x7f00
    command or shell not available

    [system] PID=15481 exiting

