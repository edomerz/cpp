CC=clang
CFLAGS=-g -std=c89 -Wall -Werror -pedantic -D_DEBUG -I .

DEPS = socket.h
OBJ = socket.o socket_test.o


all: socket_test
	

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

socket_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
