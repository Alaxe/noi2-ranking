#include<iostream>
#include<cmath>
using namespace std;

long long rot(long long c, int i)
{
    int t=c/pow(10,i-1);
    c%=(long long)pow(10,i-1);
    c*=10;
    c+=t;
    return c;
}

long long Sol1(int b, long long a)
{
    if(b!=10 || a<10)return 0;
    int i=0,I,t=a;
    long long st,fn,T;
    while(t){i++;t/=10;}I=i;
    st=1;fn=1;i--;
    while(i){st*=10;st+=2;fn*=10;fn+=9;i--;}
    st++;i=I;
    for(;st<fn;st++)
    {
        T=rot(st,i)-st;
        if(T>a)return 0;
        if(T==a)return st;
    }
    return 0;
}

int main()
{
    long long a;
    int b;
    cin>>b;
    for(int i=0;i<4;i++)
    {
        cin>>a;
        cout<<Sol1(b,a)<<endl;
    }
}