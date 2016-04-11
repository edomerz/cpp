all: string
string: string.cpp string_test.cpp
	clang++ -std=c++98 -ansi -Wall -pedantic -Werror -D_DEBUG -g string.cpp string_test.cpp -o string 
#do not put -I. in this file, it makes things go crazy, appernately because we call this file "string.h"


