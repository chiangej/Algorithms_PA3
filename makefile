# CC and CFLAGS are varilables
CC = g++ -O3
CFLAGS = -c
AR = ar
ARFLAGS = rcv
# -c option ask g++ to compile the source files, but do not link.


all	: bin/mps
	@echo -n ""

# optimized version
bin/mps	: cyclebreaker.o main.o
			$(CC)  maxPlanarSubset.o main.o -o bin/mps
main.o 	   	: src/main.cpp src/cyclebreaker.cpp
			$(CC) $(CFLAGS) $< -o $@
cyclebreaker.o	: src/cyclebreaker.cpp src/cyclebreaker.h
			$(CC) $(CFLAGS) $< -o $@

# clean all the .o and executable files
clean:
		rm -rf *.o

