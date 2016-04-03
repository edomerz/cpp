CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = q5.h
OBJ = q5.o q5_test.o

all: q5_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

q5_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
