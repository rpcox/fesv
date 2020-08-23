.PHONY : clean

CFLAGS = -Wall -Wextra -g -O0

all: execve execme fork vfork system
	@echo
	@echo " *** usage: execve execme"
	@echo " *** usage: fork"
	@echo " *** usage: vfork"
	@echo " *** usage: system"
	@echo

%.o: %.c

%: %.o
	$(CC) $(CFLAGS) $+ -o $@

clean:
	-rm -f execve execme fork vfork system
	-rm -f *.o
