#include <iostream>

using namespace std;
long long a[100000000];
long long  b[100000000];
int main()
{
long long n,k,first,mul,add,mod,sb=0,maxim,red;
cin>>n>>k;
cin>>first>>mul>>add>>mod;
sb=first;
a[0]=first;
if(k<1||k>10000000||k>n)
{
    return 0;
}
if(n<1||n>1000000||n<k)
{
    return 0;
}
if(first<1||first>1000000007||first>mod)
{
    return 0;
}
if(mul<1||mul>1000000007||mul>mod)
{
    return 0;
}
if(add<1||add>1000000007||add>mod)
{
    return 0;
}
if(mod<1||mod>1000000007||mod<first||mod<mul||mod<add)
{
    return 0;
}
else{
    for(int i=1;i<n;i++)
    {
        a[i]=(a[i-1]*mul+add)%mod;
    }
    for(int i=1;i<n;i++)
    {
    sb+=a[i];
    }
    cout<<sb;

}


/*
7 3
5 3 2 23
*/

}
