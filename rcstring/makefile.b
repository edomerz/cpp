CC=clang++
CFLAGS= -g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = buffer.h string_m.h
OBJ = string.o buffer.o buffer_test.o

all: buffer_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

buffer_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
