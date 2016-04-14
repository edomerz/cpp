all: nts_singleton
nts_singleton: non_thread_safe_singletons_test.cpp
	clang++ -std=c++98 -ansi -Wall -pedantic -Werror -D_DEBUG -g non_thread_safe_singletons_test.cpp -o nts_singleton
#do not put -I. in this file, it makes things go crazy, appernately because we call this file "string.h"


