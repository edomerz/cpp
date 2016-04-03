	
int main()
{
	int i;
	float *f = &i;
	
	const int *icp = &i;
	int *ip = icp;
	
	return(0);
}
