CC=clang++
CFLAGS=-g -std=c++98 -ansi -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = test9.h
OBJ = test9.o test9_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test9_test: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
