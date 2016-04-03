CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = gp1.h
OBJ = gp1.o gp1_test.o

all: gp1_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

gp1_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
