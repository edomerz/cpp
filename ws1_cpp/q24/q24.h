/****************************************************************************
	q24
AUTHOR: omer ido                                                   
CREATE DATE: 28/03/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __Q24_H__
#define __Q24_H__

#include <iostream> 

struct X
{
	X(int a_, int b_);

	void Inc();
	void Dec();

	int m_a;
	int m_b;
};
	
#endif /* ifndef __Q24_H__*/
