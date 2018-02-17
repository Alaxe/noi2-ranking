#include <iostream>
using namespace std;
int main()
{
    long long n,otg=1,t=10,s=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        otg=otg*i;
    }
    while(otg/t>0)
    {
        s+=(otg%t)/(t/10);
        t=t*10;
    }
    s+=(otg%t)/(t/10);
    t=t*10;
    cout<<s<<endl;

}
