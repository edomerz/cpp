CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = 
OBJ = q25_test.o

all: q25_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

q25_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
