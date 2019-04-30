CC=g++
CFLAGS=-Wall -Wpedantic -Wextra -Weffc++ -O2 -std=c++14 -o
ARMAD=-O2 -larmadillo

all: armadillo_matrix

armadillo_matrix: armadillo_matrix.o 
	$(CC) armadillo_matrix.o $(CFLAGS) armadillo_matrix $(ARMAD)

armadillo_matrix.o: armadillo_matrix.cpp
	$(CC) -c armadillo_matrix.cpp 

.PHONY: clean

clean: 
	rm -rf *.o armadillo_matrix

