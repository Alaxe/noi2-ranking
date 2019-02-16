#include <bits/stdc++.h>
using namespace std;
int main(){
long long d,m,y,v,b=0,p=0;
string t;
cin>>t>>v;
if((t[0]>='0')and(t[0]<='9')and(t[1]>='0')and(t[1]<='9'))
{
    d=int(t[0]-'0')*10+int(t[1]-'0');
    if((t[3]>='0')and(t[3]<='9')and(t[4]>='0')and(t[4]<='9'))
    {
        m=int(t[3]-'0')*10+int(t[4]-'0');
        y=int(t[6]-'0')*1000+int(t[7]-'0')*100+int(t[8]-'0')*10+int(t[9]-'0');
    }
    else
    {
        m=int(t[3]-'0');
        y=int(t[5]-'0')*1000+int(t[6]-'0')*100+int(t[7]-'0')*10+int(t[8]-'0');
    }
}
else
{
    d=int(t[0]-'0');
    if((t[2]>='0')and(t[2]<='9')and(t[3]>='0')and(t[3]<='9'))
    {
        m=int(t[2]-'0')*10+int(t[3]-'0');
        y=int(t[5]-'0')*1000+int(t[6]-'0')*100+int(t[7]-'0')*10+int(t[8]-'0');
    }
    else
    {
        m=int(t[2]-'0');
        y=int(t[4]-'0')*1000+int(t[5]-'0')*100+int(t[6]-'0')*10+int(t[7]-'0');
    }
}
if(y==2019)
{
    if(m==1)p=4;
    if(m==2)p=1;
    if(m==3)p=1;
    if(m==4)p=5;
    if(m==5)p=3;
    if(m==6)p=0;
    if(m==7)p=5;
    if(m==8)p=2;
    if(m==9)p=6;
    if(m==10)p=4;
    if(m==11)p=1;
    if(m==12)p=6;
}
if(y==2020)
{
    if(m==1)p=3;
    if(m==2)p=0;
    if(m==3)p=6;
    if(m==4)p=3;
    if(m==5)p=1;
    if(m==6)p=5;
    if(m==7)p=3;
    if(m==8)p=0;
    if(m==9)p=4;
    if(m==10)p=2;
    if(m==11)p=6;
    if(m==12)p=4;
}
while(v!=0)
{
    if(d%7==p)d=d+2;
    else if(d%7==(p+1)%7)d=d+2;
    d=d+1;
    v=v-1;
}
while(b==0)
{
    if(m==2)
    {
        if((y==2020)and(d>29))
        {
            d=d-29;
            m=m+1;
        }
        else if(d>28)
        {
            d=d-28;
            m=m+1;
        }
        else b=1;
    }
    if((m==4)or(m==6)or(m==9)or(m==11))
    {
        if(d>30)
        {
            d=d-30;
            m=m+1;
        }
        else b=1;
    }
    else
    {
        if(d>31)
        {
            m=m+1;
            d=d-31;
        }
        else b=1;
    }
    if(m>12)
    {
        y=y+1;
        m=m-12;
    }
}
if((int)(log10(d)+1)==1)cout<<"0"<<d<<".";
else cout<<d<<".";
if((int)(log10(m)+1)==1)cout<<"0"<<m<<".";
else cout<<m<<".";
cout<<y<<endl;
return 0;
}

