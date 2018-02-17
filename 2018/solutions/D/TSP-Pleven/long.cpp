#include<iostream>
using namespace std;

int main()
{
    long long n,k,ans=1,num=1;
    cin>>n>>k;
    for(int i=1;i<=n-1;i++)
    {
        num*=10;
    }
    for(int i=2;i<=num;i++)
    {
        ans=i*k*n;
        if(ans>=num) break;
    }
    cout<<ans<<endl;
    return 0;
}
