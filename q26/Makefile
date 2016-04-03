CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS =
OBJ = q26_test.o

all: q26_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

q26_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
