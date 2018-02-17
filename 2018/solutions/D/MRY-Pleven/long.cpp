#include<iostream>
using namespace std;
int main()
{
    long long n,k,a,ans;
    string num1;
    cin>>n>>k;
    num1='1';
    num1=num1+'0';
    for(int i=1;i<=n-2;i++)
    {
        num1=num1+'0';
    }
    ans=num1[1];
    for(int i=2;i<=n;i++)
    {
        a=num1[i];
        ans=ans*10+a;
    }
    cout<<ans<<endl;
    return 0;
}
