#include <iostream>
#include <string>
#include <cmath>
#include <vector>

long long raise(long long n, int to)
{
	for(int i = 2; i <= to; i++)
		n*= n;

	return n;
}

long long BDec(std::string a, int base)
{
	long long res = 0;
	int curNum;

	for(int i = a.length()-1; i >= 0; i--)
	{
		if(a[i] >= '0' && a[i] <= '9')
			curNum = a[i] - 48;
		else if(a[i] == 'A')
			curNum = 10;
		else if(a[i] == 'B')
			curNum = 11;
		else if(a[i] == 'C')
			curNum = 12;
		else if(a[i] == 'D')
			curNum = 13;
		else if(a[i] == 'E')
			curNum = 14;
		else if(a[i] == 'F')
			curNum = 15;

		int on = a.length() - i-1;
		res += curNum * pow((double)base, on);
	}

	return res;
}

void DecB(long long a, int base)
{
	if(base == 10 || a == 0)
	{
		std::cout<<'\n'<< a;
		return;
	}

	std::string res = "";

		int cur;

		while(a!= 0)
		{
			cur = (a & (base-1));
			if(cur == 0)
				res+='0';
			else if(cur>= 0 && cur <= 9)
				res+= (char)(cur + 48);
			else if(cur > 10)
				res+=(char)(cur -10 + 97);

			a/=base;
		}

		std::string answer = "";

		for(int i= 0; i < res.length(); i++)
		{
			answer+=res[res.length()-i-1];
		}

		std::cout <<'\n'<< answer;
}

int FindNuls(int n)
{
	int counter = 0;

	while(n > 0)
	{
		n/=10;
		counter++;
	}

	return counter;
}

long long ReverseNum(long long n, int nuls)
{
	std::vector<int> digits;

	while(n != 0)
	{
		digits.push_back(n%10);

		n/=10;
	}
	
	long long reversed = digits[nuls];
	
	for(int i =nuls-1; i >= 0; i--)
	{
		reversed += digits[i] * pow(10.0, i+1);
	}

	return reversed;
}

long long FindAnswer(long long a, int len)
{
	for(int i = pow(10.0, len); i < pow(10.0,len+1); i++)
	{
		if(-i + ReverseNum(i, len) == a)
		{
			return i;
		}
	}

	return 0;
}

int main()
{
	int b;
	std::string n1, n2,n3,n4;
	int a1, a2,a3,a4;
	std::cin>>b>>n1>>n2>>n3>>n4;
	
	a1 = BDec(n1, b);
	a2 = BDec(n2, b);
	a3 = BDec(n3, b);
	a4 = BDec(n4, b);

	int len1 = FindNuls(a1) -1;
	int len2 = FindNuls(a2) -1;
	int len3 = FindNuls(a3) -1;
	int len4 = FindNuls(a4) -1;
	
	a1 = FindAnswer(a1, len1);
	a2 = FindAnswer(a2, len2);
	a3 = FindAnswer(a3, len3);
	a4 = FindAnswer(a4, len4);
	
	DecB(a1, b);
	DecB(a2, b);
	DecB(a3, b);
	DecB(a4, b);

	return 0;
}