CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = game1.h
OBJ = game1.o game1_test.o

all: game1_test
	

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

game1_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
