#include "counter.h"

namespace ilrd
{

void Counter::Inc()
{
	++m_c;
}

void Counter::Print()
{
	printf("counter is: %lu\n", m_c);
}

}
