foo()
{
	String str1 = "hello";
}
/*
initialization of str1 with a string, this is c format

1. non explicit Ctor
2. Dtor must free the allocated spce for the stinrg buffer created by the Ctor
3. non generated assignment operator= to prevent memory leaks such as

	String str2;
	str1 = str2; // no free of str1 buffer, this is a memory leak. this will happen in // generated assignment operator

	write an =op that deletes str1 before , take note to handle self assignment.

*/