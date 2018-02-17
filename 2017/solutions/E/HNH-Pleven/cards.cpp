#include<iostream>
using namespace std;
int main()
{
    long long a,b,a1,b1,n,br1,n1,n2,ans;
    cin>>n;
    cin>>a>>b;
    n2=1;
    br1=0;
    n1=0;
    if(a>=1000000)
    {
        cout<<n1;
        if(a<=0)
        {
            cout<<n1;
        }
    }
    if(b>=1000000)
    {
        cout<<n1;
        if(b<=0)
        {
            cout<<n1;
        }
    }
    ans=(a-a1)+(b-b1)-3;
    cout<<ans<<endl;
    return 0;
}
