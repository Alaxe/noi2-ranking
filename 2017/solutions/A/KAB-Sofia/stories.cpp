#include<iostream>
using namespace std;
int main()
{
    long long n,k;
    cin>>n>>k;
    long long A[n];
    long long first,mul,add,mod;
    cin>>first>>mul>>add>>mod;
    A[0]=first;
    mul=mul%mod;
    add=add%mod;
    for(long long s=1;s<n;s++)
    {
        A[s]=((A[s-1]%mod)*mul+add)%mod;
    }

    long long ind=0;
    long long sum=0;
    long long gol=0;
    for(long long p=0;p<n;p++)
    {
    if(p-ind>=k)
    {
        ind=p-k+1;
        for(int t=p-k+1;t<p+1;t++)
        {
           if(A[t]>A[ind])
           {
               ind=t;
           }
        }
    }
    if(A[p]>A[ind])
    {
        ind=p;
    }
    sum=sum+A[ind];
    }
    cout<<sum<<endl;
    return 0;
}
