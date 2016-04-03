CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS =
OBJ = new_vector_test.o

all: new_vector_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

new_vector_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
