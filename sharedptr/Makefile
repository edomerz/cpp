CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = sharedptr.h
OBJ = sharedptr.o sharedptr_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sharedptr_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
