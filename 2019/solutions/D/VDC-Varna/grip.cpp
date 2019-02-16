#include<iostream>
using namespace std;
int main()
{
    int d,m,y;
    char s1,s2;
    cin>>d>>s1>>m>>s2>>y;
    int n;
    cin>>n;
    int ost=0;
    d+=6;
    ost=n-5;
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
         d+=ost;
        if(d>31)
        {
            d=d-31;
            if(m==12)
            {
                y++;
            }
             m++;
        }
    }
    if(m==4||m==6||m==9||m==11)
    {
         d+=ost;
        if(d>30)
        {
            d=d-30;
            m++;
        }

    }
    if(m==2)
    {
        d+=ost;
        if(y%4==0&&y%100!=0||y%400==0)
        {
            if(d>29)
            {
                d=d-29;
                m++;
            }
        }
        else
        {
            if(d>28)
            {
                d=d-28;
                m++;
            }
        }

    }
    if(d<10)
    {
        cout<<"0"<<d<<".";
    }
    else cout<<d<<".";
    if(m<10)
    {
        cout<<"0"<<m<<".";
    }
    else cout<<m<<".";
    cout<<y<<endl;
    return 0;
}
