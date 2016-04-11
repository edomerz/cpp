CC=clang++
CFLAGS= -g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = rcstring.h buffer.h string_m.h proxy.h
OBJ = rcstring.o string.o proxy.o proxy_test.o

all: proxy_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

proxy_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
