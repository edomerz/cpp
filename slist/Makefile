CC=clang++
CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = slist.h
OBJ = slist.o slist_test.o

all: slist_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

slist_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
