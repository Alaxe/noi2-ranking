#include<iostream>
using namespace std;
int n,k;
int len;
int comb()
{
    int com;
    int sum1=1;
    int sum2=1;
    int n1=n-1;
    int n2=n1;
    do
    {
     sum1*=n1;
     n1=n1-1;
    }while(n1!=n2-len);
    do
    {
        sum2*=len;
        len=len-1;
    }while(len!=0);
    com=sum1/sum2;
    return com;
}
int main()
{
    cin>>n>>k;
    len =n-k;
    if(k==1||k==n)cout<<1<<endl;
    else
    {
        cout<<comb()<<endl;
    }
    return 0;
}
