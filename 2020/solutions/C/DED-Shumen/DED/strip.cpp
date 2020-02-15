#include<iostream>
using namespace std;
int n,k,m;
int lenta(int n,int k)
{
    if(k==1||k==n)return 1;
    if(k==2||k==n-1)return n-1;
    return n-2+lenta(n-1,k);
}
int main()
{
    cin>>n>>k;
    m=lenta(n,k);
    cout<<m<<'\n';
}
