#include <iostream>
#include <string>

const int bigNum = 101;

int counter = 0;
bool hasBeen[bigNum][bigNum];

bool IsPalindrom(std::string a)
{
	for(int i = 0; i < a.length(); i++)
	{
		if(a[i] != a[a.length() - i - 1])
			return false;
	}

	return true;
}

std::string remove(std::string a, int index)
{
	return a.erase(index, 1);
}

void FindPalindromes(std::string n)
{
	if(n.length() == 1)
	{
		counter++;
		return;
	}

	if(IsPalindrom(n))
	{
		counter++;
	}

	for(int k = 0; k < n.length(); k++)
		FindPalindromes(remove(n, k));

	int wait = 5;
}

int main()
{
	std::string n;
	std::string reverse = "";

	//return 0;
	std::cin>>n;

	for(int i = 0; i < n.length(); i++)
		reverse+=n[n.length() - i -1];

	FindPalindromes(n);


	std::cout<< counter;

	return 0;
}