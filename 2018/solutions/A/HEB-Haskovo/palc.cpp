#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
unsigned long long M1,M2,M3,M4;
unsigned long long m,br;
unsigned long long dis,e;
unsigned long long i;
int brs;
int main()
{
    cin>>brs;
    cin>>M1>>M2>>M3>>M4;
    if(M1%9!=0)cout<<0<<endl;
    else
    {
        m=8,br=1;
        while(M1>m*9)
        {
            br++;
            m=m*10+8;
        }
        dis=10;
        for(i=1;i<br;i++)
        {
            dis*=10;
        }
        e=dis*10;
        for(i=dis;i<e;i++)
        {
            unsigned long long a=((i*10+i/dis)%e)-i;
            if(a==M1){cout<<i<<endl;break;}
        }
    }
    if(M2%9!=0)cout<<0<<endl;
    else
    {
        m=8,br=1;
        while(M2>m*9)
        {
            br++;
            m=m*10+8;
        }
        dis=10;
        for(i=1;i<br;i++)
        {
            dis*=10;
        }
        e=dis*10;
        for(i=dis;i<e;i++)
        {
            unsigned long long a=((i*10+i/dis)%e)-i;
            if(a==M2){cout<<i<<endl;break;}
        }
    }
    if(M3%9!=0)cout<<0<<endl;
    else
    {
        m=8,br=1;
        while(M3>m*9)
        {
            br++;
            m=m*10+8;
        }
        dis=10;
        for(i=1;i<br;i++)
        {
            dis*=10;
        }
        e=dis*10;
        for(i=dis;i<e;i++)
        {
            unsigned long long a=((i*10+i/dis)%e)-i;
            if(a==M3){cout<<i<<endl;break;}
        }
    }
    if(M4%9!=0)cout<<0<<endl;
    else
    {
        m=8,br=1;
        while(M4>m*9)
        {
            br++;
            m=m*10+8;
        }
        dis=10;
        for(i=1;i<br;i++)
        {
            dis*=10;
        }
        e=dis*10;
        for(i=dis;i<e;i++)
        {
            unsigned long long a=((i*10+i/dis)%e)-i;
            if(a==M4){cout<<i<<endl;break;}
        }
    }
    return 0;
}
