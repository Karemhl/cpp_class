CC=g++
CFLAGS=-Wall -Wpedantic -Wextra -Weffc++ -O2 -std=c++14 -o

all: matrix

matrix: matrix.o mainmatrix.o 
	$(CC) matrix.o mainmatrix.o $(CFLAGS) matrix

mainmatrix.o: mainmatrix.cpp
	$(CC) -c mainmatrix.cpp 

matrix.o: matrix.cpp matrix.h
	$(CC) -c matrix.cpp

.PHONY: clean

clean: 
	rm -rf *.o matrix

