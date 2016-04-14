#include "nts_singleton.h"

using namespace ilrd;

int main(int argc, char* argv[], char** envp)
{
	char* s;
	s = "hello";
	Log log(s);
	
	Singleton<Log> sing = Singleton<Log>::GetInst();

	return(0);
}
