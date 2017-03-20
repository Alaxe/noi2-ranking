#include<iostream>
using namespace std;

int n,k;
unsigned long long a[10000000],sum;
unsigned long long first,mul,add,mod;

unsigned long long next(unsigned long long t)
{
    return (((t*mul)%mod)+add)%mod;
}

void fill()
{
    sum=first;
    //cout<<sum;
    unsigned long long p=first;
    for(int i=0;i<k;i++)a[i]=p;
    for(int i=1;i<n;i++)
    {
        p=next(p);
        a[k+i-1]=p;
        for(int j=k+i-2;j>=i;j--)
        {
            if(a[j]>p)break;
            a[j]=p;
        }
        //cout<<' '<<a[i];
        sum+=a[i];
    }
}

int main()
{
	cin>>n>>k>>first>>mul>>add>>mod;
	fill();
	cout<<sum<<endl;
	return 0;
}