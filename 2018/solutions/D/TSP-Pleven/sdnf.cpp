#include<iostream>
#include<string>
using namespace std;

int main()
{
    long long n,num=1,ans=1,j;
    int q,w,e,r,t,y,u,i,o,p;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        num*=i;
    }
    q=num%10;
    w=num%100/10;
    e=num%1000/100;
    r=num%10000/1000;
    t=num%100000/10000;
    y=num%1000000/100000;
    u=num%10000000/1000000;
    i=num%100000000/10000000;
    o=num%1000000000/100000000;
    p=num/1000000000;
    cout<<q+w+e+r+t+y+u+i+o+p<<endl;
    return 0;
}
