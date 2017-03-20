#include <iostream>
#include <string>
using namespace std;
int f(string s)
{
    int d=0, m=0, r=0;
    if (s.size()==5)
    {
        d=(s[0]-48)*10+(s[1]-48);
        m=(s[3]-48)*10+(s[4]-48);
    }
    else
    {
        if (s.size()==3)
        {
            d=s[0]-48;
            m=s[2]-48;
        }
        else
        {
            if (s[1]=='/')
            {
                d=s[0]-48;
                m=(s[2]-48)*10+(s[3]-48);
            }
            else
            {
                d=(s[0]-48)*10+(s[1]-48);
                m=s[3]-48;
            }
        }
    }
    if (m==1) r=d;
    if (m==2) r=31+d;
    if (m==3) r=31+28+d;
    if (m==4) r=31+28+31+d;
    if (m==5) r=31+28+31+30+d;
    if (m==6) r=31+28+31+30+31+d;
    if (m==7) r=31+28+31+30+31+30+d;
    if (m==8) r=31+28+31+30+31+30+31+d;
    if (m==9) r=31+28+31+30+31+30+31+31+d;
    if (m==10) r=31+28+31+30+31+30+31+31+30+d;
    if (m==11) r=31+28+31+30+31+30+31+31+30+31+d;
    if (m==12) r=31+28+31+30+31+30+31+31+30+31+30+d;
    return r;
}
int diof1(int a, int b)
{
    int a2=0;
    int x=0, y=0;
    while (true)
    {
        a2=a+23*x;

        if ((a2-b)%28==0) {y=(a2-b)/28; break;}
        x++;
    }
    return a2;
}
int diof2(int a, int b)
{
    int a2=0;
    int x=0, y=0;
    while (true)
    {
        a2=a+644*x;
        if ((a2-b)%33==0) {y=(a2-b)/33; break;}
        x++;
    }
    return a2;
}
int main()
{
    string s1, s2, s3, s4;
    cin>>s1>>s2>>s3>>s4;
    int d1, d2, d3, d4, d;
    d1=f(s1);
    d2=f(s2);
    d3=f(s3);
    d4=f(s4);
    //while (d1<d2) d1+=23;
   // cout<<diof1(d1, d2)<<endl;
    d=diof2(diof1(d1, d2), d3);
   // cout<<d<<endl;
    d=d%21252;
    if (d==d4) cout<<"21252\n";
    if (d4<d) cout<<d-d4<<endl;
    if (d4>d) cout<<21252-(d4-d)<<endl;
}
