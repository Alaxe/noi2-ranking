#include<iostream>
using namespace std;

bool saed(long long m, long long a1, long long b1, long long c1)
{
    while(m)
    {
        if(m%10==a1 || m%10==b1 || m%10==c1) return false;
        m/=10;
    }
    return true;
}
int main()
{
    long long n, l, a=1, m=0, pech[3]={10, 10, 10}, br;
    cin>>n;
    cin>>l;
    for(int i=0; i<l; i++)
    {
        cin>>pech[i];
    }
    if(pech[1]>9) pech[1]=pech[0];
    if(pech[2]>9) pech[2]=pech[0];
    while(n)
    {
        if(saed(a, pech[0], pech[1], pech[2]))
        {
            m=a;
            n--;
        }
        a++;
        while(a>=100000 && (a/100000%10==pech[0] || a/100000%10==pech[1] || a/100000%10==pech[2])){a=a+100000+a%100000;}
        while(a>=10000 && (a/10000%10==pech[0] || a/10000%10==pech[1] || a/10000%10==pech[2])){a=a+10000+a%10000;}
        while(a>=1000 && (a/1000%10==pech[0] || a/1000%10==pech[1] || a/1000%10==pech[2])){a=a+1000+a%1000;}
        while(a>=100 && (a/100%10==pech[0] || a/100%10==pech[1] || a/100%10==pech[2])){a=a+100+a%100;}
        while(a>=10 && (a/10%10==pech[0] || a/10%10==pech[1] || a/10%10==pech[2])){a=a+10+a%10;}
    }
    cout<<m<<endl;
    return 0;
}
