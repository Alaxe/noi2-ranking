#include<iostream>
using namespace std;
int main()
{
    long long a,b,ans;
    cin>>a;
    b=1;
    for(int i=2;i<=a;i++)
    {
        b=b*i;
    }
    ans=b%10;
    b=b/10;
    for(int i=2;i<=b;i++)
    {
        ans=ans+b%10;
        b=b/10;
    }
    ans=ans+b%10;
    cout<<ans<<endl;
    return 0;
}
