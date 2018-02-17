#include <iostream>
#include <string>

int ConvertBin(unsigned int a, int z)
{
	int counter = 0;

	while(a != 1)
	{
		if((a&1) == 0)
		{
			counter++;
		}

		a = a >> 1;
	}

	return counter;
}

int main()
{
	unsigned int s,t,z;

	int a = 8;
	int b = (a & 1);

	std::cin>>s >> t>>z;

	int counter = 0;

	for(int i = s; i <= t; i++)
	{
		if(ConvertBin(i, z) == z)
			counter++;
	}

	std::cout << counter;

	return 0;
}