CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = prodcon.h
OBJ = prodcon.o prodcon_test.o

all: prodcon_test
	

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

prodcon_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
