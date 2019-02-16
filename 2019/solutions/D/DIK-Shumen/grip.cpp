#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int d,m,y;
int month(int x,int yx)
{
    if (x==1||x==3||x==5||x==7||x==8||x==10||x==12)return 31;
    else
    if (x==4||x==6||x==9||x==11)return 30;
    else
    if (yx%400==0||yx%100!=0&&yx%4==0)return 29;
    else return 28;
}
int main()
{
    string s;
    cin>>s;
    int i=0,sz=s.size();
    while(s[i]!='/')
    {
        d=d*10+(s[i]-'0');
        i++;
    }i++;
    while(s[i]!='/')
    {
        m=m*10+(s[i]-'0');
        i++;
    }i++;
    while(i<sz)
    {
        y=y*10+(s[i]-'0');
        i++;
    }
    int w=2;
    int d2=1,m2=1,y2=2019;
    while(d2!=d||m2!=m||y2!=y)
    {
        d2++;
        if (d2>month(m2,y2))
        {
            d2=d2-month(m2,y2);
            m2++;
            if (m2==13)
            {
                m2=1;
                y2++;
            }
        }
        w++;
        if (w==8)w=1;
    }
    int t;
    cin>>t;
    int cnt=0;
    while(cnt<=t)
    {
        if (w!=6&&w!=7)cnt++;
        w++;
        if (w==8)w=1;
        d++;
        if (d>month(m,y))
        {
            d=d-month(m,y);
            m++;
            if (m==13)
            {
                m=1;
                y++;
            }
        }
    }
    d--;
    if (d==0)
    {
        m--;
        if (m==0)
        {
            m=12;
            y--;
        }
        d=month(m,y);
    }

    if (d<10)cout<<"0";
    cout<<d<<".";
    if (m<10)cout<<"0";
    cout<<m<<".";
    cout<<y<<endl;
    return 0;
}
