CC=clang++
CFLAGS= -g -std=c++98 -Wall -Werror -pedantic -D_DEBUG  -I .
DEPS=tcpacceptor.h tcpstream.h
OBJ=server.o tcpacceptor.o tcpstream.o

all: server

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

server: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

