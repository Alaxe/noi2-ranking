#include<bits/stdc++.h>
using namespace std;
long long d, m, y;
char c;
int main()
{
    cin>>d>>c>>m>>c>>y;
    long long n, days=0;
    cin>>n;

    if(y==2019)
    {
        if(m==1)days=d;
        if(m==2)days=d+31;
        if(m==3)days=d+31+28;
        if(m==4)days=d+31+28+31;
        if(m==5)days=d+31+28+31+30;
        if(m==6)days=d+31+28+31+30+31;
        if(m==7)days=d+31+28+31+30+31+30;
        if(m==8)days=d+31+28+31+30+31+30+31;
        if(m==9)days=d+31+28+31+30+31+30+31+31;
        if(m==10)days=d+31+28+31+30+31+30+31+31+30;
        if(m==11)days=d+31+28+31+30+31+30+31+31+30+31;
        if(m==12)days=d+31+28+31+30+31+30+31+31+30+31+30;
    }
    else
    {
        if(m==1)days=d;
        if(m==2)days=d+31;
        if(m==3)days=d+31+29;
        if(m==4)days=d+31+29+31;
        if(m==5)days=d+31+29+31+30;
        if(m==6)days=d+31+29+31+30+31;
        if(m==7)days=d+31+29+31+30+31+30;
        if(m==8)days=d+31+29+31+30+31+30+31;
        if(m==9)days=d+31+29+31+30+31+30+31+31;
        if(m==10)days=d+31+29+31+30+31+30+31+31+30;
        if(m==11)days=d+31+29+31+30+31+30+31+31+30+31;
        if(m==12)days=d+31+29+31+30+31+30+31+31+30+31+30;
    }
    long long week=(days%7+2)%7;
    if(week==0)week=7;

    long long a=week+n;
    long long b=(a/5)*7+a%5;
    long long c=b-week+d;
    if(c==6||c==7)c=1;
    c=c-d;
    days=days+c;

    if(days>365){y=2020;
    days=days-365;}
    else(y=2019);
    if(y==2019)
    {
        if(days<32){m=1;
        d=days;}
        else
        if(days<60){m=2;
        d=days-31;}
        else
        if(days<91){m=3;
        d=days-59;}
        else
        if(days<121){m=4;
        d=days-90;}
         else
        if(days<152){m=5;
        d=days-120;}
         else
        if(days<182){m=6;
        d=days-151;}
         else
        if(days<213){m=7;
        d=days-181;}
         else
        if(days<244){m=8;
        d=days-212;}
         else
        if(days<274){m=9;
        d=days-243;}
         else
        if(days<305){m=10;
        d=days-273;}
         else
        if(days<335){m=11;
        d=days-304;}
         else
        if(days<366){m=12;
        d=days-334;}
    }
    if(y==2020)
    {
        if(days<32){m=1;
        d=days;}
        else
        if(days<61){m=2;
        d=days-32;}
        else
        if(days<92){m=3;
        d=days-60;}
        else
        if(days<122){m=4;
        d=days-91;}
         else
        if(days<153){m=5;
        d=days-121;}
         else
        if(days<183){m=6;
        d=days-152;}
         else
        if(days<214){m=7;
        d=days-182;}
         else
        if(days<245){m=8;
        d=days-213;}
         else
        if(days<275){m=9;
        d=days-244;}
         else
        if(days<306){m=10;
        d=days-274;}
         else
        if(days<336){m=11;
        d=days-305;}
         else
        if(days<367){m=12;
        d=days-335;}
    }if(d<10)cout<<"0"<<d<<".";
    else cout<<d<<".";
    if(m<10)cout<<"0"<<m<<".";
    else cout<<m<<".";
    cout<<y<<endl;
    return 0;
}
