#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int compare(string s1,string s2)
{
    if(s1.size()>s2.size())return 0;
    else if(s1.size()<s2.size())return 1;
    else for(int i=0;i<s1.size();i++)
    {
        if(s1[i]>s2[i])return 0;
        else if(s1[i]<s2[i])return 1;
    }
    return 2;
}

string add(string s1,string s2)
{
    string s("");
    int ost=0,x,y,n,m;
    if(s1.size()<s2.size())swap(s1,s2);
    n=s1.size();
    m=s2.size();
    for(int i=0;i<n-m;i++)s2="0"+s2;
    for(int i=0;i<n;i++)
    {
        x=s1[n-i-1]-'0';
        y=s2[n-i-1]-'0';
        if(x+y+ost>9)
        {
            s=char((x+y+ost)%10+'0')+s;
            ost=(x+y+ost)/10;
        }
        else
        {
            s=char(x+y+ost+'0')+s;
            ost=0;
        }
    }
    if(ost>0)s=char(ost+'0')+s;
    return s;
}

string substract(string s1,string s2)
{
    string s(""),news("");
    int n,m,x,y,ost=0;
    n=s1.size();
    m=s2.size();
    for(int i=0;i<n-m;i++)s2="0"+s2;
    for(int i=0;i<n;i++)
    {
        x=s1[n-i-1]-'0';
        y=s2[n-i-1]-'0';
        if((x+ost)>=y)
        {
            s=char(x+ost-y+'0')+s;
            ost=0;
        }
        else
        {
            s=char(10+x+ost-y+'0')+s;
            ost=-1;
        }
    }
    int i=0;
    while(s[i]=='0')i++;
    for(i;i<s.size();i++)news+=s[i];
    if(news.size()==0)news+='0';
    return news;
}

string mult(string s1,string s2)
{
    string s="0",k;
    int n,m,t,ost;
    n=s1.size();
    m=s2.size();
    for(int i=0;i<n;i++)
    {
        k="";ost=0;
        for(int j=0;j<m;j++)
        {
            t=(s1[n-i-1]-'0')*(s2[m-j-1]-'0')+ost;
            k=char(t%10+'0')+k;
            ost=t/10;
        }
        if(ost>0)k=char(ost+'0')+k;
        for(int j=0;j<i;j++)k=k+"0";
        s=add(s,k);
    }
    return s;
}

string div2(string k)
{
    string s("");
    int ost=0,t,n;
    n=k.size();
    for(int i=0;i<n;i++)
    {
        t=ost*10+k[i]-'0';
        ost=t%2;
        s+=char(t/2+'0');
        if(s[0]=='0')s="";
    }
    return s;
}

string bsearch(string k)
{
    string x="0",y=k,m,v;
    while(compare(add(x,"1"),y)==1)
    {
        m=div2(add(x,y));
        if(compare(mult(m,add(m,"1")),k)==0)y=m;
        else x=m;
    }
    return x;
}

int main()
{
    ios::sync_with_stdio(false);
    string m,n;
    cin>>m>>n;
    cout<<substract(bsearch(n),bsearch(m))<<endl;
    return 0;
}
