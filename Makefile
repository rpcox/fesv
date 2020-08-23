.PHONY:  install
package  = fesv
version  = 1.0

all clean exec fork vfork system:
	$(MAKE) -C src $@

install:
	@echo " *** Nothing to install. Execute from src/"

