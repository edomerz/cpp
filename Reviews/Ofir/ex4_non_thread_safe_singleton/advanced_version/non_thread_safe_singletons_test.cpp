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
	void PrintLogName(){ cout << m_name << endl;};
	void WriteFinishedToLog(const char *string_);
	void PrintFinished(){ cout << m_finished << endl;};
	
private:
	friend class Singleton<LogSingleton>; // allowing access to the Singleton class.
								   // without it, we have no access to  
	explicit LogSingleton(){}; // we, the users, want nobody to instantiate LogSingleton
	~LogSingleton();
	char *m_name;
	char *m_finished;
};

class KeyBoardSingleton
{
public:	
	void SetKeyBoardName(const char *string_);
private:
	friend class Singleton<KeyBoardSingleton>;
	explicit KeyBoardSingleton(){}; 
	~KeyBoardSingleton() { Singleton<LogSingleton>::GetInstance().WriteFinishedToLog("finished"); };
	char *m_name;
};


static char *AllocAndCopy(const char *string_)
{
	size_t string_length = strlen(string_)+1; 
	char *dest_ = new char[string_length]; 
	return(static_cast<char *>(memcpy(dest_, string_, string_length))); 
}

void LogSingleton::SetLogName(const char *string_)
{
	m_name = AllocAndCopy(string_);
}

void LogSingleton::WriteFinishedToLog(const char *string_)
{
	m_finished = AllocAndCopy(string_);
}

LogSingleton::~LogSingleton()
{
	Singleton<LogSingleton>::GetInstance().PrintFinished();
	delete[] m_name;
}

void KeyBoardSingleton::SetKeyBoardName(const char *string_)
{
	m_name = AllocAndCopy(string_);
}



int main()
{
	Singleton<KeyBoardSingleton>::GetInstance().SetKeyBoardName("Keyboard 1");
	Singleton<LogSingleton>::GetInstance().SetLogName("Keyboard Log");
	Singleton<LogSingleton>::GetInstance().PrintLogName();
	
	// LogSingleton log1; // correctly issues an error: we, as users, dont want to
						  //	allow instantiation of another log;
	// Singleton<LogSingleton> log1; // correctly issues an error: we, as implementors, 
								     // dont want to allow instantiation of another 
								     // singleton;
	
	printf("ssss\n");
	return (0);

}



