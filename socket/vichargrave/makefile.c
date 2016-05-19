CC=clang++
CFLAGS= -g -std=c++98 -Wall -Werror -pedantic -D_DEBUG  -I .
DEPS=tcpconnector.h tcpstream.h
OBJ=client.o tcpconnector.o tcpstream.o

all: client

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

client: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

