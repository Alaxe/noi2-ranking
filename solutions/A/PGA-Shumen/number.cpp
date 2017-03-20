#include<iostream>
#include<cstring>
using namespace std;
/*int n[128],m[128];
int sum[](int s1[], int s2[])
{
    int sz=s2.size();
    int s[128];
    for(int i=0;i<sz;i++)
    {
        s[i]+=(s1[i]+s2[i])%10+'0';
        s[i+1]=(s1[i]+s2[i])/10;
    }
    s[sz]+='0';
    return s;
}
string sub(string s1, string s2)
{
    int i,sz=s2.size();
    string s;
    for(i=sz-1;i>=0;i--)
    {
        s[i]=s2[i]-s1[i]+'0';
        if(s[i]<'0')
        {
            s[i]+=10;
            s2[i-1]--;
        }
    }
    return s;
}
string div(string s1)
{
    int i,sz=s1.size();
    string s;
    int j=sz-1;
    int x=0;
    int l=0;
    for(i=sz-1;i>0;i--)
    {
        x+=s[i]-'0';
        if(x<2)
        {
            s[i]='0';
            continue;
        }
        s[i]=x/2+'0'+l;
        l=x%2;
        x=0;
    }
    x=(s1[0]-'0')/2;
    s[0]=x;
    return s;
}
string mul(string s1, string s2)
{
    int sz1=s1.size();
    int sz2=s2.size();
    int i,j;
    string s;
    int x;
    for(i=0;i<sz1;i++)
    {
        for(j=0;j<sz2;j++)
        {
            x=(s1[i]-'0')*(s2[i]-'0');
            s[i+j]+=x%10;
            s[i+j+1]+=x/10;
        }
    }
    return s;
}
int bigger(string s1, string s2)
{
    int i,sz1=s1.size(),sz2=s2.size();
    if(sz1<sz2) return 0;
    if(sz1>sz2) return 1;
    for(i=sz1-1;i>=0;i--)
    {
        if(s1[i]>s2[i]) return 1;
        if(s1[i]<s2[i]) return 0;
    }
    return 0;
}
int main()
{
    cin>>n>>m;
    string x,y;
    int i,j,sz;
    string l,r;
    l="0";
    r=n;
    string mid,mc;
    while(bigger(r,sum("1",l)))
    {
        mid=div(sum(l,r));
        mc=mul(mid,sum("1",mid));
        if(bigger(n,mc))
        {
            r=mid;
        }
        else
        {
            l=mid;
            x=mid;
        }
    }
    l="0";
    r=m;
    while(bigger(r,sum("1",l)))
    {
        mid=div(sum(l,r));
        mc=mul(mid,sum("1",mid));
        if(bigger(m,mc))
        {
            r=mid;
        }
        else
        {
            l=mid;
            y=mid;
        }
    }
    cout<<sub(y,x)<<endl;
    return 0;
}
*/
long long n,m;
int main()
{
    long long x=0,y=0,l,r,mid;
    cin>>n>>m;
    l=0;
    r=1e9;
    while(l+1<r)
    {
        mid=(l+r)/2;
        if(mid*(mid+1)<n)
        {
            x=mid;
            l=mid;
        }
        else r=mid;
    }
    l=0;
    r=1e9;
    while(l+1<r)
    {
        mid=(l+r)/2;
        if(mid*(mid+1)<=m)
        {
            y=mid;
            l=mid;
        }
        else r=mid;
    }
    cout<<y-x<<endl;
    return 0;
}
