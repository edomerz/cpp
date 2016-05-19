CC=clang++
IDIR=../include

CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -I$(IDIR)

ODIR=obj
LDIR = ../lib

LIBS=-L$(LDIR) -lcs -lm

all: cyclone1_test

_DEPS = cyclone1.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = cyclone1.o cyclone1_test.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

	
cyclone1_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY:clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
