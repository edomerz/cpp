CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = q35.h
OBJ = q35.o q35_test.o

all: q35_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

q35_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
