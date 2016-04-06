CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = 
OBJ = cpp2c_test.o

all: cpp2c_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cpp2c_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
