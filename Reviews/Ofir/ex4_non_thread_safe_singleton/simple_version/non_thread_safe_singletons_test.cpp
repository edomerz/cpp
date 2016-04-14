#include <iostream>
#include <cstdio>
#include <cstring>
#include "non_thread_safe_singleton.h"
using namespace std;
using namespace ilrd;

class LogSingleton
{
public:
	//void SetLogName(){ cin >> m_name;};
	void SetLogName(const char *string_);
	void PrintLogId(){ cout << m_name << endl;};
	
private:
	
	/*  we have to do that for enabling access to the Ctor of Singleton 
	 *  (specifically, to the line: static T singleton_instance) when calling
	 *  to GetInstance inside main */
	friend class Singleton<LogSingleton>;
	explicit LogSingleton(){}; // we, the users, want nobody to instantiate LogSingleton
	char *m_name;
};

void LogSingleton::SetLogName(const char *string_)
{
	size_t string_length = strlen(string_)+1; 
	char *dest_ = new char[string_length]; 
	m_name = static_cast<char *>(memcpy(dest_, string_, string_length)); 
}


int main()
{
	Singleton<LogSingleton>::GetInstance().SetLogName("Really Nice Log");
	Singleton<LogSingleton>::GetInstance().PrintLogId();
	
	// LogSingleton log1; // correctly issues an error: we, as users, dont want to
						  //	allow instantiation of another log;
	// Singleton<LogSingleton> log1; // correctly issues an error: we, as implementors, 
								     // dont want to allow instantiation of another 
								     // singleton;
	return (0);

}



