all: nts_singleton_test

CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = nts_singleton.h
OBJ = nts_singleton_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

nts_singleton_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
