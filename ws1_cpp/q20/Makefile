CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = 
OBJ = q20.o q20_test.o

all: q20_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

q20_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
