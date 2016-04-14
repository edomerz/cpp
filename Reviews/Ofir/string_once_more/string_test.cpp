#include <iostream>
#include <cstdio>
#include <sys/time.h>
#include "string.h"
using namespace std;
using namespace ilrd;

int main()
{
	String string1("hello");
	std::cout << "String string1(\"hello\"), printing string1:\n" << string1 <<
			" (expected: hello)." << endl << endl;

	String string2(string1);
	std::cout << "String string2(string1), printing string2:\n" << string2 << " (expected: hello)."
			<< endl << endl;

	String string3 = "hipopotam"; // the word "hipopotam" is implicitly converted into String
	string2 = string3;
	std::cout << "String string3(\"hipopotam\"), string2 = string3, printing string2:\n" <<
			"string2 is now: " << string2 <<  " (expected: hipopotam)." << endl << endl;

	string1[4] = string2[4]; // this test only the operator[] function
	std::cout << "string1[4] = string2[4], printing string2:\n" <<
				"string1 is now: " << string1 <<  " (expected: hellp)." << endl << endl;

	bool result1 = (string2[4] == 'p'); // this test only the operator[] function, too
	printf("is string2[4] == p? %s\n\n", result1 ? "yes" : "no");

	bool result2 = (string2 == string3);
	printf("checking operator==:\nis string2 == string3? %s\n\n", result2 ? "yes" : "no");

	const String string4 = string2; // NOTE: this is NOT(!!!) using the asignment operator, but the
									// the copy Ctor. the reason is simple: this is not an assignment,
									// but initialization.
	std::cout << "String string4 = string2, printing string4:\n" << string4 << " (expected: hipopotam)."
					<< endl << endl;

	string3 = string1;
	std::cout << "string3 = string1, printing string3:\n" << string3 << " (expected: hellp)."
						<< endl << endl;

	string3 = string2;
	std::cout << "string3 = string2, printing string3:\n" << string3 << " (expected: hipopotam)."
						<< endl << endl;

	string3 = string3; // checking self-assignment doesn't cause errors. note that eclipse gives an
					   // error, but it compiles and run.
	std::cout << "string3 = string3, printing string3:\n" << string3 << " (expected: hipopotam)."
						<< endl << endl;



	// string4[3] = 'c'; // this will issue error, and this error is thanks to the const operator[]
						 // function - we did it exactly to protect the user from changing a const.


	return (0);

}






