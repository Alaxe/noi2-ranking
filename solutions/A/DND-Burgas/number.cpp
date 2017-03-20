#include<iostream>
using namespace std;
unsigned long long calc(unsigned long long index)
{
	unsigned long long item;
	unsigned long long uvelichitel = index*2+4;
	if(index%2==0)
	{
		item = (index/2)*uvelichitel+uvelichitel/2;
	}
	else
	{
		item = ((index/2)+1)*uvelichitel;
	}
	return item;
}
int main()
{
	unsigned long long n,m;
	cin>>m>>n;
	unsigned long long adder  = 2;
	unsigned long long left=1,right=1000000000;
	unsigned long long upper = 0,lower = 0;
	bool flag = true;
	while(left<right)
	{
		unsigned long long mid = (left+right)/2;
		unsigned long long number = calc(mid);
		//cout<<number<<endl;
		if(n==number)
		{
			upper = mid+1;
			flag = false;
		}
		if(n>number)
		{
			left = mid+1;
		}
		else if(mid!=0)
		{
			right = mid-1;
		}
		else{
			flag = false;
			right = 0;
			upper = 0;
		}
	}
	if(flag)
	{
		if(calc(right)<=n)
		{
			upper = right+1;
		}
		else
		{
			upper = right;
		}
	}
	//cout<<upper<<endl;
	flag = true;
	left = 0;
	right = 1000000000;
	while(left<right)
	{
		unsigned long long mid = (left+right)/2;
		unsigned long long number = calc(mid);
		//cout<<number<<"left="<<left<<"right="<<right<<endl;
		if(m==number)
		{
			lower = mid+1;
			flag = false;
		}
		if(m>number)
		{
			left = mid+1;
		}
		else if(mid!=0){
		right = mid-1;
		}
		else
		{
			flag = false;
			right = 0;
			lower = 0;
		}
	}
	if(flag)
	{
		if(calc(right)<=m)
		{
			lower = right+1;
		}
		else
		lower = right;
	}
	cout<<upper-lower<<endl;
	return 0;
}
