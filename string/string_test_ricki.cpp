
/*
 * string_test.cpp
 *
 *  Created on: 31/03/2016
 *      Author: Ricki Yaish
 */
		
#include <iostream>
#include <string>

#include "string_m.h"

using namespace ilrd;


int main(int argc, char **argv, char **penv)
{
	using namespace std;

	String s1("hello");
	String s2 = "world";
	String s3(s1);
	const String const_s4 = "I'm a const string";
	String s5;

	cout<<"1) Initialize strings via the different methods:"<<endl;
	cout<<"   String s1(\"hello\")        => s1: "<< s1<<endl;
	cout<<"   String s2 = \"world\"       => s2: "<< s2<<endl;
	cout<<"   String s3(s1)             => s3: "<< s3<<endl;
	cout<<"   String s4 (empty string)  => s4: \""<< s5<<"\"\n"<<endl;

	cout<<"2) Lengths of strings:"<<endl;
	cout<<"   length(s1) = "<< s1.Length()<<endl;
	cout<<"   length(s4) (empty string) = "<< s5.Length()<<'\n'<<endl;

	cout<<"3) Compare strings:"<<endl;
	cout<<"   Does s1 == s1: "<< ((s1==s3)?"Yes":"No")<<endl;
	cout<<"   Does s1 == \"hello\": "<< ((s1=="hello")?"Yes":"No")<<endl;
	cout<<"   Does \"world\" == s1: "<< ((s1=="world")?"Yes":"No")<<'\n'<<endl;

	cout<<"4) Operator[]:"<<endl;
	cout<<"   For s2: "<<s2<<" ==> s2[3]='A' ==> "; s2[3] = 'A'; cout<<s2<<endl;
	cout<<"   For const_s4: "<<const_s4<<" ==> const_s4[6] = "<<const_s4[6]<<'\n'<<endl;

	return 0;
}

