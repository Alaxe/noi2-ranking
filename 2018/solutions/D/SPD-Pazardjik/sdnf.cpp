#include <iostream>
using namespace std;
int main()
{
    unsigned long long n,f=1,s=0,cntr=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        f=f*i;
    while(f>0)
    {
        s+=f%10;
        f/=10;
    }
    cout<<s<<endl;
    return 0;
}
