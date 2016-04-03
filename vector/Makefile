CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = vector.h
OBJ = vector.o vector_test.o

all: vector_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

vector_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
