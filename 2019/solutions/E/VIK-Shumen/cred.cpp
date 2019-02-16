#include<iostream>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;
int br=0;
if(m<10)
{int ed=n%10;
    for(int i=0;i<=m;i++)
    {
        if(n+ed<=m)
        {
        br++;
        n=n+ed;
        ed=n+ed;
        }

    }
}
if(m>9&&m<100)
{
    int ed=n%10;
    int des=n/10;
    for(int i=10;i<=m;i++)
    {
    if(n+ed+des<=m)
    {
        br++;
        n=ed+des;
        ed=(n+ed+des)%10;
        des=(n+ed+des)/10;
    }
    }
}
if(m>99&&m<1000)
{
        int ed=n%10;
        int des=n/10%10;
        int st=n/100;
        for(int i=100;i<=m;i++)
        {
            br++;
            n=ed+des+st;
            ed=(n+ed+des+st)%10;
            des=(n+ed+des+st)/10%10;
            st=(n+ed+des+st)/100;
        }
}
if(m>999&&m<10000)
{
    int ed=n%10;
        int des=n/10%10;
        int st=n/100%100;
        int h=n/1000;
        for(int i=1000;i<=m;i++)
        {
            br++;
            n=ed+des+st+h;
            ed=(n+ed+des+st+h)%10;
            des=(n+ed+des+st+h)/10%10;
            st=(n+ed+des+st+h)/100%10;
            h=(n+ed+des+st+h)/1000;
        }
}
if(m>9999&&m<=100000)
{  int ed=n%10;
        int des=n/10%10;
        int st=n/100%10;
        int h=n/1000%10;
        int dh=n/10000%10;
        int sh=n/100000;
        for(int i=1000;i<=m;i++)
        {
            br++;
            n=ed+des+st+h+dh+sh;
            ed=(n+ed+des+st+h+dh+sh)%10;
            des=(n+ed+des+st+h+dh+sh)/10%10;
            st=(n+ed+des+st+h+dh+sh)/100%10;
            h=(n+ed+des+st+h+dh+sh)/1000%10;
            dh=(n+ed+des+st+h+dh+sh)/10000;
        }
}
cout<<br<<endl;


return 0;
}
