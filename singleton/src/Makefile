CC=clang++
IDIR=../include

CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I$(IDIR)

ODIR=obj
LDIR = ../lib

LIBS=-L$(LDIR) -lcs -lm

all: singleton_test

_DEPS = singleton.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = singleton.o singleton_test.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

	
singleton_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY:clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
