CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = serializer.h
OBJ = serializer.o serializer_test.o

all: serializer_test
	

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

serializer_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
