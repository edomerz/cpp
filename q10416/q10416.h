/****************************************************************************
	q10416
AUTHOR: omer ido                                                   
CREATE DATE: 10/04/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __Q10416_H__
#define __Q10416_H__

#include <iostream> 

/*
 * req:
 * String("hello");
 * String s2(s1);
 * String s3;
 * s3 = s2;
 * char c = s3[7];
 *
 */


namespace ilrd
{
char* CreateString(const char* str);

class String
{
public:
	String(const char* str = "");
	~String();
	String(const String& other_);
	String& operator=(const String& other_);
	const char& operator[](size_t index);
	
private:
	char *m_str;
};
}


#endif /* ifndef __Q10416_H__*/
