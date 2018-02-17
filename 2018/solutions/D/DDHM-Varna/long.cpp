#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long sumsize=0,sum1,n,k,sum=1;
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        sum1=sum;
        sum*=10;
        sum%=k;
        if(sum==sum1)break;
    }
    if(sum==0)
    {
        cout<<1;
        for(int i=1;i<n;i++)cout<<0;
        cout<<endl;
        return 0;
    }
    sum=k-sum;
    sum1=sum;
    while(sum1)
    {
        sum1/=10;
        sumsize++;
    }
    if(sumsize==n)
    {
        cout<<sum<<endl;
    }
    else
    {
        cout<<1;
        for(int i=1;i<n-sumsize;i++)cout<<0;
        cout<<sum<<endl;
    }
return 0;
}
//100
