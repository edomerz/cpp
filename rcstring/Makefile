CC=clang++
CFLAGS= -g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = string_m.h rcstring.h
OBJ =  string.o rcstring.o rcstring_test.o

all: rcstring_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

rcstring_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
