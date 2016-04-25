#CC=clang++
#CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
#DEPS = tree.h
#OBJ = tree.o tree_test.o
#
#all: tree_test
#
#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)
#
#
#tree_test: $(OBJ)
#	$(CC) -o $@ $^ $(CFLAGS)

CC=clang++
CFLAGS= -g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = tree.h
OBJ = tree.o tree_test.o

all: tree_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tree_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
