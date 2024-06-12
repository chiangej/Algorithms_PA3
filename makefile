## CC and CFLAGS are varilables
#CC = g++ -O3
#CFLAGS = -c
#AR = ar
#ARFLAGS = rcv
## -c option ask g++ to compile the source files, but do not link.
#
#
#all	: bin/cb
#	@echo -n ""
#
## optimized version
#bin/cb	: cyclebreaker.o main.o
#			$(CC)  cyclebreaker.o main.o -o bin/cb
#main.o 	   	: src/main.cpp src/cyclebreaker.cpp
#			$(CC) $(CFLAGS) $< -o $@
#cyclebreaker.o	: src/cyclebreaker.cpp src/cyclebreaker.h
#			$(CC) $(CFLAGS) $< -o $@
#
## clean all the .o and executable files
#clean:
#		rm -rf *.o

CC = g++
CFLAGS = -c
AR = ar
ARFLAGS = rcv
DBGFLAGS = -g -D_DEBUG_ON_
OPTFLAGS = -O3

all	: bin/cb
	@echo -n ""

bin/cb	: cb.o main.o
			$(CC) $(OPTFLAGS) cb.o main.o -o bin/cb
main.o 	: src/main.cpp src/cyclebreaker.h
			$(CC) $(CFLAGS) $< -o $@
cb.o	: src/cyclebreaker.cpp src/cyclebreaker.h
			$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@

clean:
		rm -rf *.o lib/*.a lib/*.o bin/*

