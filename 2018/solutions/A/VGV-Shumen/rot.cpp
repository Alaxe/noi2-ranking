#include <iostream>
#include <cstdio>
using namespace std;
int h,l;
long long int a;
int Log(long long int a)
{
    int br=0;
    while(a!=0)
    {
        br++;
        a/=10;
    }
    return br;
}
long long int Pr(int st[], int log)
{
    long long int temp=1,otg=0;
    for(int i=log-1;i>=0;i--)
    {
        otg+=st[i]*temp;
        temp*=10;
    }
    return otg;
}
long long int Pr1(int st[], int log)
{
    long long int temp=10,otg=0;
    for(int i=log-1;i>0;i--)
    {
        otg+=st[i]*temp;
        temp*=10;
    }
    otg+=st[0];
    return otg;
}
void Print(int st[],int log)
{
    for(int i=0;i<log;i++)
    {
        cout<<st[i];
    }
    cout<<endl;
}
long long int Req(int log, int curr,int st[])
{
    if(l==1) return 0;
    if(curr<log)
    {
        for(int i=0;i<=9;i++)
        {
            st[curr]=i;
            Req(log,curr+1,st);
        }
    }
    if(curr==log)
    {
        if(Pr1(st,log)-Pr(st,log)==a)
        {
           Print(st,log);
           l=1;
        }
    }
}
void Resh(long long int x)
{
   int log=Log(a);
   int st[log];
   for(int i=1;i<=9;i++)
   {
       st[0]=i;
       Req(log,1,st);
   }
}
void Read()
{
    cin>>h;
    for(int i=0;i<4;i++)
    {
        cin>>a;
        if(a%9!=0) cout<<0<<endl;
        else Resh(a);
        l=0;
    }
}
int main()
{
    Read();
    return 0;
}
