#include<iostream>
using namespace std;
int main()
{
    long long n,K,prn,nk,chp,kprn;
    cin>>n;
    prn=n-1;
    nk=n;
    kprn=n-1;
    chp=prn+(kprn*kprn);
    K=chp+1;
    cout<<K<<endl;
    return 0;
}
