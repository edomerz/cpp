/*
 * ex1.c
 *
 *  Created on: Apr 19, 2016
 *      Author: fullstack
 */


#include <stdio.h>
#include <string.h>

/*
 * return the clk speed of the cpu in MHz, as in /proc/cpuinfo
 * in multiple cpu's return the 1st
 * on error return 0
 */

float GetCpuClkSpeed()
{
	FILE *fp;
	char buffer[1024];
	size_t bytes_read;
	char *match;
	float clk_speed;

	fp = fopen("/proc/cpuinfo", "r");
	if(!fp)
	{
		return(1);
	}

	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, fp);

	fclose(fp);

	if(!bytes_read || bytes_read == sizeof(buffer))
	{
		return(2);
	}

	buffer[bytes_read] = '\0';

	match = strstr(buffer, "cpu MHz");
	if(!match)
	{
		return(3);
	}

	sscanf(match, "cpu MHz		: %f", &clk_speed);
//	sscanf(match, "processor %f", &clk_speed);
	return(clk_speed);
}

int main()
{
	float ret = GetCpuClkSpeed();
	printf("clk speed: %4.0f MHz\n", ret);

	return(0);
}
