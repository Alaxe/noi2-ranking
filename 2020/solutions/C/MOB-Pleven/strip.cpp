#include<iostream>
using namespace std;
unsigned long long n,k;
unsigned long long a[51][51];
unsigned long long rek(unsigned long long beg,unsigned long long en)
{
    if(beg==k && en==k)return 1;
    if(beg==k){if(a[beg][en-1]==0)a[beg][en-1]=rek(beg,en-1);return a[beg][en-1];}
    if(en==k){if(a[beg+1][en]==0)a[beg+1][en]=rek(beg+1,en);return a[beg+1][en];}
    if(a[beg][en-1]==0)a[beg][en-1]=rek(beg,en-1);
    if(a[beg+1][en]==0)a[beg+1][en]=rek(beg+1,en);
    return a[beg][en-1]+a[beg+1][en];
}
int main()
{
    cin>>n>>k;
    cout<<rek(1,n)<<endl;
return 0;
}
