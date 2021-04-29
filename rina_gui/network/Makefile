		 CC = g++
TEST_CC = gcc
CCFLAGS = -Wall -Werror -g
LDFLAGS = -lm -lrina-api -lrlite-conf
OBJECTS = main.o network.o netconf.o flowstat.o ipcpstat.o rlite-ctl.o ipcptable.o

project_root = $(shell pwd)

network: $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) && make clean

main.o: main.cpp
	$(CC) -c $^

network.o: network.c network.h
	$(CC) -c network.c

nettools.o: nettools.c nettools.h
	$(CC) -c nettools.c

netconf.o: netconf.cpp netconf.hpp
	$(CC) -c netconf.cpp

flowstat.o: flowstat.cpp flowstat.hpp netstat.hpp
	$(CC) -c flowstat.cpp

ipcpstat.o: ipcpstat.cpp ipcpstat.hpp netstat.hpp
	$(CC) -c ipcpstat.cpp

ipcptable.o: ipcptable.cpp ipcptable.hpp
	$(CC) -c ipcptable.cpp

rlite-ctl.o: rlite-ctl.c rlite-ctl.h
	$(TEST_CC) -c rlite-ctl.c

test: test.c
	$(TEST_CC) -o $@ $^ $(LDFLAGS)
.PHONY: test

clean:
	@rm -rf *.o *.gch
.PHONY: clean

purge: clean
	@rm -rf network
.PHONY: purge
