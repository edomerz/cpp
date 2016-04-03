CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = q24.h
OBJ = q24.o q24_test.o

all: q24_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

q24_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
