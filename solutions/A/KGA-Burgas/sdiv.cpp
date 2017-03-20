/*
Sample 1:
	Input
		1234
		4 2
	Output
		0

Sample 2:
	Input
		222
		2 10
	Output
		7

Sample 3:
	Input
		02
		2 10
	Output
		3
*/

#include <iostream>
#include <string>

using namespace std;

unsigned int ToNumber(const string &S, const unsigned long long BitMask)
{
	string New;
	for(unsigned int I = 0; I < S.size(); ++I)
	{
		if(BitMask & (1ull << I))
		{
			New.push_back(S[I]);
		}
	}

	unsigned int N = 0;
	for(unsigned int I = 0; I < New.size(); ++I)
	{
		N *= 10;
		N += New[I] - '0';
	}	
	return N;
}

int main()
{
	string S;
	unsigned int n;
	unsigned long long m;

	cin >> S;
	cin >> n >> m;

	unsigned long long Count = 0;
	const unsigned long long BitMaskEnd = 1 << S.size();
	for(unsigned long long BitMask = 1; BitMask < BitMaskEnd; ++BitMask)
	{
		if((ToNumber(S, BitMask) % n) == 0)
		{
			++Count;
		}
	}
	cout << Count % m << endl;
}