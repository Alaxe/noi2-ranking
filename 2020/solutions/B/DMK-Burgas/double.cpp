#include "pch.h"
#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	int arr[50], contone, conttwo, n, sumone = 0, sumtwo = 0, min = 0, j = 0;
	bool check = false;
	cin >> n >> contone >> conttwo;
	if (1 < n && n < 200 && 0 < contone && contone < 200 && 0 < conttwo && conttwo < 200)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (arr[i] > 100)
			{
				check = true;
			}
		}
		if (check == false)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (j != 0)
					{
						if (arr[j] <= arr[j - 1])
						{
							swap(arr[j], arr[j - 1]);
						}
					}
				}
			}
			j = 0;
			for (int i = 0; i < n; i++)
			{
				if (sumone < contone)
				{
					sumone += arr[i];
					if (sumone > contone)
						if (sumone > contone)
						{
							sumone -= arr[j++];
						}
				}
			}
			j = 0;
			for (int i = 0; i < n; i++)
			{
				if (sumtwo < conttwo)
				{
					sumtwo += arr[i];
					if (sumtwo > conttwo)
					{
						sumtwo -= arr[j++];
					}
				}
			}
			if (sumtwo < 0)
			{
				sumtwo = 0;
			}
			if (sumone < 0)
			{
				sumone = 0;
			}
			cout << sumone + sumtwo;
		}
	}
}