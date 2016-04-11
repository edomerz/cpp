
/*
 * rcstring_test.cpp
 *
 *  Created on: 06/04/2016
 *      Author: Ricki Yaish
 */
		
#include <iostream>
#include <string>

#include "rcstring.h"

int main(int argc, char **argv, char **penv)
{
	using namespace ilrd;
	using namespace std;

	cout <<"operation: RCString s1 = \"hello\";\n";
	RCString s1 = "hello";
	cout << s1 << " -> s1 reference count: " << s1.GetRefCount() <<"\n\n";

	cout <<"operation: RCString s2;\n";
	RCString s2;
	cout << s2 << " -> s2 reference count: " << s2.GetRefCount() <<"\n\n";

	cout <<"operation: s2 = s1;\n";
	s2 = s1;

	cout << s1 << " -> s1 reference count: " << s1.GetRefCount() <<"\n";
	cout << s2 << " -> s2 reference count: " << s2.GetRefCount() <<"\n\n";

	cout <<"operation: RCString s3(s2);\n";
	RCString s3(s2);
	cout << s3 << " -> s3 reference count: " << s3.GetRefCount() <<"\n\n";

	cout <<"operation: s1 = s1;\n";
	s1 = s1;
	cout << s1 << " -> s1 reference count: " << s1.GetRefCount() <<"\n\n";

	cout <<"operation: s1[3] = 'A';\n";
	s1[3] = 'A';
	cout << s1 << " -> s1 reference count: " << s1.GetRefCount() <<"\n";
	cout << s2 << " -> s2 reference count: " << s2.GetRefCount() <<"\n";
	cout << s3 << " -> s3 reference count: " << s3.GetRefCount() <<"\n\n";

	cout <<"operation: s2[3] = 'A';\n";
	s2[3] = 'A';
	cout << s2 << " -> s2 reference count: " << s2.GetRefCount() <<"\n";
	cout << s3 << " -> s3 reference count: " << s3.GetRefCount() <<"\n\n";

	cout <<"operation: s3[3] = 'A';\n";
	s3[3] = 'A';
	cout << s3 << " -> s3 reference count: " << s3.GetRefCount() <<"\n\n";

	/*******************************************************************/
	RCString s11("hello");
	RCString s22 = "world";
	RCString s33(s11);
	const RCString const_s4 = "I'm a const string";
	RCString s5;

	cout<<"1) Initialize strings via the different methods:"<<endl;
	cout<<"   String s1(\"hello\")        => s1: "<< s11<<endl;
	cout<<"   String s2 = \"world\"       => s2: "<< s22<<endl;
	cout<<"   String s3(s1)             => s3: "<< s33<<endl;
	cout<<"   String s4 (empty string)  => s4: \""<< s5<<"\"\n"<<endl;

	cout<<"2) Lengths of strings:"<<endl;
	cout<<"   length(s1) = "<< s11.Length()<<endl;
	cout<<"   length(s4) (empty string) = "<< s5.Length()<<'\n'<<endl;

	cout<<"3) Compare strings:"<<endl;
	cout<<"   Does s1 == s3: "<< ((s11==s33)?"Yes":"No")<<endl;
	cout<<"   Does s1 == \"hello\": "<< ((s11=="hello")?"Yes":"No")<<endl;
	cout<<"   Does \"world\" == s1: "<< ((s11=="world")?"Yes":"No")<<'\n'<<endl;

	cout<<"4) Operator[]:"<<endl;
	cout<<"   For s2: "<<s22<<" ==> s2[3]='A' ==> "; s22[3] = 'A'; cout<<s22<<endl;
	cout<<"   For const_s4: "<<const_s4<<" ==> const_s4[6] = "<<const_s4[6]<<'\n'<<endl;

	return 0;
}

