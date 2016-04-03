/****************************************************************************
	test9
AUTHOR: omer ido                                                   
CREATE DATE: 22/03/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __TEST9_H__
#define __TEST9_H__

#include <iostream> 
	
#endif /* ifndef __TEST9_H__*/


//~/o/test9$ gcc test9.c
//test9.c: In function ‘main’:
//test9.c:5:13: warning: initialization from incompatible pointer type [enabled by default]
//  float *f = &i;
//             ^
//test9.c:8:12: warning: initialization discards ‘const’ qualifier from pointer target type [enabled by default]
//  int *ip = icp;
//            ^
//~/o/test9$ g++ test9_test.cpp
//test9_test.cpp: In function ‘int main()’:
//test9_test.cpp:5:14: error: cannot convert ‘int*’ to ‘float*’ in initialization
//  float *f = &i;
//              ^
//test9_test.cpp:8:12: error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
//  int *ip = icp;
//            ^
//~/o/test9$ clang test9.c
//test9.c:5:9: warning: incompatible pointer types initializing 'float *' with an expression of type
//      'int *' [-Wincompatible-pointer-types]
//        float *f = &i;
//               ^   ~~
//test9.c:8:7: warning: initializing 'int *' with an expression of type 'const int *' discards
//      qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
//        int *ip = icp;
//             ^    ~~~
//2 warnings generated.
//~/o/test9$ clang++ test9_test.cpp
//test9_test.cpp:5:9: error: cannot initialize a variable of type 'float *' with an rvalue of type
//      'int *'
//        float *f = &i;
//               ^   ~~
//test9_test.cpp:8:7: error: cannot initialize a variable of type 'int *' with an lvalue of type
//      'const int *'
//        int *ip = icp;
//             ^    ~~~
//2 errors generated.

