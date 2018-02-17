#include <iostream>
using namespace std;
int main()
{
    long long n,m,k,s=0,minm,min1=9999,c;
    cin>>m>>k;
    while(1)
    {
        cin>>n;
        if(n%2==0) s+=n;
        if(n-m>0) minm=n-m;
        else minm=m-n;
        if(minm<min1) min1=minm;
        if(n-m==min1 || m-n==min1) c=n;
        if(s>k) break;
    }
    cout<<c<<" "<<s<<endl;
    return 0;
}
