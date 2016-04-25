#CC=clang++
#CFLAGS=-g -std=c++98 -Wall -Werror -pedantic -D_DEBUG -lboost_system -lboost_thread -lpthread -I .
#DEPS = fsq.h circ_buf.h
#OBJ = circ_buf.o fsq.o fsq_test.o
#
#all: fsq_test
#	
#
#%.o: %.cpp $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)
#
#fsq_test: $(OBJ)
#	$(CC) -o $@ $^ $(CFLAGS)

fsq:
	make -f makefile.fsq

circ:
	make -f makefile.circ
