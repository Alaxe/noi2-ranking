/*
Sample 1:
	Input
		7 1
	Output
		0

Sample 2:
	Input
		1 20
	Output
		4
*/

#include <iostream>

using namespace std;

// Big Unsigned Integer type
typedef unsigned long long BUI;

BUI Div2(BUI N)
{
	return N*(N+1);
}

unsigned int Log2(const BUI N)
{
	unsigned int Result = 63;
	for(BUI I = 1ull << 63; I; I >>= 1)
	{
		if(N & I)
		{
			break;
		}
		--Result;
	}

	return Result;
}

int main()
{
	BUI M, N;
	cin >> M >> N;
	
	int c1=0, c2=0, c3=0, c4=0;

	// Lower Bound
	const unsigned int DigitsGuessLB = Log2(M)/2;
	BUI LB = 1ull << DigitsGuessLB;
	if(Div2(LB) < M)
	{
		for(; Div2(LB) < M; ++LB)
		{
			++c1;
		}
	}
	else
	{
		for(; Div2(LB) >= M; --LB)
		{
			++c2;
		}
		++LB;
	}

	cout << endl;

	// Upper Bound
	const unsigned int DigitsGuessUB = Log2(M)/2;
	BUI UB = 1ull << DigitsGuessUB;
	if(Div2(UB) < N)
	{
		unsigned long long Factor = 1;
		for(; Div2(UB) <= N; ++UB)
		{
			++c3;
		}
		--UB;
	}
	else
	{
		for(; Div2(UB) > N; --UB)
		{
			++c4;
		}
	}

	if(LB > UB)    // Not necessary, but more clear
	{
		cout << 0 << endl;
	}
	else
	{
		cout << UB-LB + 1 << endl;
	}
}