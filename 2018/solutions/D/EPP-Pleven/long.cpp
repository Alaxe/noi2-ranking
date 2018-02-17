#include<iostream>
using namespace std;
int main()
{
    long long n,k,a,ans;
    cin>>n>>k;
    a=1;
    for(int i=1; i<=n-1; i++)
    {
        a=a*10;
    }
    for(int i=1; ; i++)
    {
        if(a%k==0)
        {
            ans=a;
            break;
        }
        a++;
    }
    cout<<ans<<endl;
    return 0;
}
