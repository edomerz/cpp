CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = lockless_queue.h
OBJ = lockless_queue.o lockless_queue_test.o

all: lockless_queue_test
	

%.o: %.c $(DEPS)
	clang++ -c -o $@ $< $(CFLAGS)

lockless_queue_test: $(OBJ)
	clang++ -o $@ $^ $(CFLAGS)
