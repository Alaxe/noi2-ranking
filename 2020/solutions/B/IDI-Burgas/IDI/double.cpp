#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int a[200], cont1[200], cont2[200];
	int n, w1, w2;
	int i, sum = 0, sumW1 = 0, sumW2 = 0, sumHA1 = 0, sumHA2 = 0;
	cin >> n >> w1 >> w2;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n / 2; i++)
	{
		sumHA1 += a[i];
	}
	for (int i = n / 2; i < n; i++)
	{
		sumHA2 += a[i];
	}
	cout<<sumHA2;
	
	
}

