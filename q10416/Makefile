CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = q10416.h
OBJ = q10416.o q10416_test.o

all: q10416_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

q10416_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
