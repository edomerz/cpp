#include "gp1.h"
	
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word1 = "Game";
	string word2 ("Over");
	string word3(3, '!');

	string phrase = word1 + " " + word2 + word3;
	cout<<"the phrase is: "<< phrase<< "\n\n";

	cout<< "the phrase has"<< phrase.size()<<" char in it.\n";

	cout<< "\n the seq 'Over' begins at location: "<< phrase.find("Over")<<endl;
	
	if(phrase.find("eggplant") == string::npos)
	{
		cout<< "eggplant not in the phrase\n\n";
	}

	phrase.erase();
	phrase.empty();

	return 0;
}
