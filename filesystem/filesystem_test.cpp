#include "filesystem.h"
	
int main(int argc, char* argv[], char** envp)
{
	char diskname[] = "/dev/sda1";

	std::ifstream disk(diskname, std::ios_base::binary);

	if(!disk)
	{
		std::string str = std::string("error opening");
		throw(std::runtime_error(str + strerror(errno)));
	}

	disk.seekg(0);

	std::vector<char> buffer(512);

	disk.read(&buffer[0], 512);
	
	for(int i = 0; i < 512; ++i)
	{
		printf("%x", buffer[i]);

	}

	
	return(0);
}
