#include <iostream>
#include <string>

using namespace std;

string num;
string original;

int mid;
bool even;

bool palindromeCheck(string x);
bool checkStart;


void solvePalindromeEven();
void solvePalindromeOdd();
void solveEasyEven();
void solveEasyOdd();
void solveUnexecuted();
void solveHardEven();
void solveHardOdd();

int main()
{
	cin >> num;
	//num = "55955";
	original = num;

	if(num.size() % 2 == 0)
		even = 1;
	if(even == 1)
		mid = num.size() / 2 - 1;
	else
		mid = num.size() / 2;

	checkStart = palindromeCheck(num);

	///If the number we get is already a palindrome
	if(checkStart == 1)
	{
		if(even == 0)
			solvePalindromeOdd();
		else
			solvePalindromeEven();
	}
	else
	{
		if(even == 1)
		{
			if( int(num[mid]) > int(num[mid + 1]) )
			{
				solveEasyEven();
			}
			else
			{
				solveHardEven();
			}
		}
		else
		{
			if( int(num[mid - 1]) > int(num[mid + 1]) )
			{
				solveEasyOdd();
			}
			else
			{
				solveHardOdd();
			}
		}
	}

	return 0;
}

///palindromCheck
bool palindromeCheck(string x)
{
	for(int i = 0;i < x.size(); ++i)
	{
		if(x[i] != x[x.size() - i - 1])
			return 0;
	}
	return 1;
}

///solveUnexecuted
void solveUnexecuted()
{
	for(int i = 0; i < original.size() + 1; ++i)
	{
		if(i == 0)
			num[i] = '1';
		else if(i == original.size())
					num = num + '1';
		else
			num[i] = '0';
	}
}

///solvePalindromeOdd()
void solvePalindromeOdd()
{
	bool executed = 0;///are all the numbers 9s
	for(int i = mid;i < num.size(); ++i)
	{
		if(num[i] != '9' && num[mid - (i - mid)] != '9')
		{
			if(i == mid - (i - mid))
				num[i] = char(num[i] + 1);
			else{
			num[i] = char(num[i] + 1);
			num[mid - (i - mid)] = char(num[mid - (i - mid)] + 1);}

			executed = 1;
			break;
		}
	}
	if(executed == 0)
		solveUnexecuted();
	cout << num << endl;
}

///solvePalindromeEven()
void solvePalindromeEven()
{
	bool executed = 0;///are all the numbers 9s
	for(int i = mid + 1;i < num.size(); ++i)
	{
		if(num[i] != '9' && num[mid - (i - mid - 1)] != '9')
		{
			num[i] = char(num[i] + 1);
			num[mid - (i - mid - 1)] = char(num[mid - (i - mid - 1)] + 1);

			executed = 1;
			break;
		}
	}
	if(executed == 0)
		solveUnexecuted();
	cout << num << endl;
}

///solveEasyEven()
void solveEasyEven()
{
	for(int i = mid + 1;i < num.size(); ++i)
	{
		num[i] = num[mid - (i - mid - 1)];
	}
	cout << num << endl;
}

///solveEasyOdd()
void solveEasyOdd()
{
	for(int i = mid;i < num.size(); ++i)
	{
		num[i] = num[mid - (i - mid)];
	}
	cout << num << endl;
}

///solveHardEven()
void solveHardEven()
{
	for(int i = mid + 1;i < num.size(); ++i)
	{
		if(i == mid + 1)
		{
			num[i - 1] = num[i];
		}
		else
		{
			num[i] = num[mid - (i - mid - 1)];
		}
	}
	cout << num << endl;
}

///solveHardOdd()
void solveHardOdd()
{
	for(int i = mid + 1;i < num.size(); ++i)
	{
		if(i == mid + 1)
		{
			num[i - 2] = num[i];
		}
		else
		{
			num[i] = num[mid - (i - mid)];
		}
	}
	cout << num << endl;
}

