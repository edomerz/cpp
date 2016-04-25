CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = scopelock.h
OBJ = scopelock.o scopelock_test.o

all: scopelock_test
	

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

scopelock_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
