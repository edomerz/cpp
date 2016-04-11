#include "q10416.h"

using namespace std;
using namespace ilrd;
int main(void)
{
	String s1("hello");
	String s2(s1);
	String s3;
	s3 = s2;
//	char c = s3[7];

	char c = s3[4];
	cout << "c: " << c << endl;

	return(0);
}
