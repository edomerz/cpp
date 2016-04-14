CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = 
OBJ = string.o string_test.o

all: string_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

string_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
