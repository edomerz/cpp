CC=clang
CFLAGS=-g -std=c99 -Wall -D_DEBUG -I .
DEPS = 
OBJ = cpp2c.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cpp2c: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
