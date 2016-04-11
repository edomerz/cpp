#include "q35.h"

int main(void)
{
	try
	{
		Bar();
	}
	catch(BadDog& b)
	{
		cerr << "bad dog exception: " << b.what();
		exit(3);
	}
	catch(exception& r)
	{
		cerr << "unkwond exception: " << r.what();
		exit(4);
	}
	catch(bad_alloc)
	{
		cerr << "out of memory! exiting,";
		exit(2);
	}
	return(0);
}
