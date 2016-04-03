CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = 
OBJ = complex_test.o

all: complex_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

complex_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
