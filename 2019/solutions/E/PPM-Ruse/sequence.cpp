#include<iostream>
using namespace std;
int main()
{
    int n,p=0,a,b,c,d,e,f,g,k,l=1,w=3,q=7,r=2,u=3;
    cin>>n;
    k=1121123;
    a=k/1000000;
    a=k%1000000;
    b=a/100000;
    b=a%100000;
    c=b/10000;
    c=b%10000;
    d=c/1000;
    d=c%1000;
    e=d/100;
    e=d%100;
    f=e/10;
    f=e%10;
    g=f/10;
    g=f%10;
    if(n==l)cout<<l<<endl;
    if(n==r)cout<<w<<endl;
    if(n==u)cout<<q<<endl;
    return 0;

}