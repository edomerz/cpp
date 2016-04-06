CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = q28.h
OBJ = q28_test.o

all: q28_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

q28_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
