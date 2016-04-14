#include <cstdio>


#include "string_m.h"
	
int main(void)
{
	printf("\n[FILE:%s][func:%s][LINE:%d]%s:\n", __FILE__, __func__, __LINE__, "s1"); /* DEBUG!!! */
	ilrd::String s1("abcde"); // posible because of the non explicit constructor
	std::cout<<"\nlen s1: "<<s1.Length()<<'\n';
	char s[]	= { 'a', 'b', 'c'};
	ilrd::String s5(s);
	ilrd::String s2;
	std::cout<<"\nlen s2: "<<s2.Length()<<'\n';

	s2 = s1;
	

	ilrd::String s3(s2);
	std::cout<<"s1:"<<s1<<"	"<<"\nlen s: "<<s3.Length()<<'\n';

//	std::cout<<s1;

	std::cout<<"s1:"<<s1<<"	"<<"s2:"<<s2<<"	"<<"(s1 == s2): "<<(s1 == s2)<<'\n';
	std::cout<<"s1:"<<s1<<"	"<<"s3:"<<s3<<"	"<<"(s1 == s3): "<<(s1 == s3)<<'\n';

	s3 = "abc";
	std::cout<<"s1:"<<s1<<"	"<<"s3:"<<s3<<"	"<<"(s1 == s3): "<<(s1 == s3)<<'\n';

	std::cout<<"s3[0]: "<<s3[0]<<'\n';
	s3[0] = 'z';
	std::cout<<"s3[0]: "<<s3[0]<<'\n';

	return(0);

}
