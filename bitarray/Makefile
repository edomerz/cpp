CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = bitarray.h
OBJ = bitarray_test.o

all: bitarray_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bitarray_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
