CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = filesystem.h
OBJ = filesystem_test.o

all: filesystem_test
	

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

filesystem_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
