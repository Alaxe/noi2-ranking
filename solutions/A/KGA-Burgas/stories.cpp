/*
Sample 1:
	Input
		7 3
		5 3 2 23
	Output
		79

Sample 2:
	Input
		133742 666
		20 3 17 1000000007
	Output
		133403869908674
*/

#include <iostream>

using namespace std;

int main()
{
	unsigned int N, K;
	unsigned int FIRST, MUL, ADD, MOD;

	cin >> N >> K;
	cin >> FIRST >> MUL >> ADD >> MOD;

	unsigned long long LevelN = FIRST;
	unsigned long long LocalMax = LevelN;
	unsigned long long LocalMaxIndex = 0;
	unsigned int ReSearchIndex = 0;
	unsigned long long Sum = FIRST;
	for(unsigned int I = 1; I < N; ++I)
	{
		LevelN = (LevelN*MUL + ADD) % MOD;

		if((I - LocalMaxIndex) >= K)
		{
			ReSearchIndex = I;
			I = LocalMaxIndex;
			LevelN = LocalMax;
			LocalMax = 0;
			continue;
		}
		if(LocalMax <= LevelN)
		{
			LocalMax = LevelN;
			LocalMaxIndex = I;
		}
		
		if(ReSearchIndex <= I)
		{
			ReSearchIndex = 0;
			Sum += LocalMax;
		}
	}
	cout << Sum << '\n';
}