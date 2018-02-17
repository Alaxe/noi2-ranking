#include <iostream>
using namespace std;
int main()
{
    long long n,q,i,p,s,r=0,l;
    
    cin>>n>>p;
    for(i=1;i<n;i++)
    {cin>>s;
    if(p<s) r=r+(s-p);
    else r=r+(p-s);
    }
    cin>>q;
    l=r*q;
    cout<<l<<endl;
    return 0;
}
