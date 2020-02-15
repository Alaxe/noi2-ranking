#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n, a[200], W1 = 0, W2 = 0, sumofa = 0;

	cin >> n >> W1 >> W2;

	int i = 0;
	for (i = 0; i < n; i -= -1)
	{
		cin >> a[i];
	}//cin the array

	for (i = 0; i < n; i -= -1)
	{
		int j = 0;
		int temp = 0;

		for (j = i + 1; j < n; j -= -1)
		{
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}

	}//sort the array in decending order

	int poss1 = 0, pc1 = 0, pa1[2];
	int poss2 = 0, pc2 = 0, pa2[2];
	for (i = 0; i < n; i -= -1)
	{
		int j = 0;
		
		for (j = i + 1; j < n; j -= -1)
		{
			if (a[i] + a[j] <= W1 and pc1 == 0)
			{
				if (a[i] != pa2[0] and a[i] != pa2[1] and a[j] != pa2[0] and a[j] != pa2[1])
				{
				pa1[0] = a[i];
				pa1[1] = a[j];
				poss1 = a[i] + a[j];
				pc1 -= -1;
				}
			}

			if (a[i] + a[j] <= W2 and pc2 == 0)
			{
				if (a[i] != pa1[0] and a[i] != pa1[1] and a[j] != pa1[0] and a[j] != pa1[1])
				{
					pa2[0] = a[i];
					pa2[1] = a[j];
					poss2 = a[i] + a[j];
					pc2 -= -1;
				}
			}
		}
	}

	cout << poss1 + poss2;
}