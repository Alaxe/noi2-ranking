#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
int f;
int main()
{
	long long n,sum,ans=0;
	cin>>n;
	sum=n;
	for(int i=2; i<n; i++)
	{
	    sum*=i;
	}
	while(sum)
	{
	    ans+=sum%10;
	    sum/=10;
	}
	cout<<ans<<endl;
	return 0;
}
