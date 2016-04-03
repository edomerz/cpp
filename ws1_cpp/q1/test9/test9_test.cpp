	
int main()
{
	int i;
	float *f = &i;
	
	const int *icp = &i;
	int *ip = icp;
	
	typeof(icp);

	return(0);
}
