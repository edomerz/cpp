#include "q28.h"
	
int main(void)
{
	B* b1 = new B;
	B* b2 = new X;

	cout<<endl <<"main b1:"<<endl;
	b1->Print1();
	b1->Print2();
	b1->Print3();

	cout<<endl <<"main b2:"<<endl;
	b2->Print1();
	b2->Print2();
	b2->Print3();

	X* xx = static_cast<X*>(b2);
	cout<<endl << "main xx:"<<endl;
	xx->Print2();
	b2->Print2();

	delete b1;
	delete b2;
	
	return(0);
}
