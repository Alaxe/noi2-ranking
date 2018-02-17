#include<iostream>
using namespace std;
int main ()
{
    long long n,mm,q,i,grow=0,maxmm1=0,maxmm2=0;
    cin>>n;
    cin>>mm;
    maxmm1=mm;
    for(i=2;i<=n;i++)
    {
    cin>>mm;
    if(mm>maxmm2)maxmm2=mm;
    if(mm<maxmm2)grow+=maxmm2-mm;
    }
    if(maxmm1<maxmm2)grow+=maxmm2-maxmm1;
    cin>>q;
    cout<<grow*q<<endl;
    return 0;
}