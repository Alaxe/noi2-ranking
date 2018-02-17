#include<iostream>
#include<string>
using namespace std;
string sum(string s1, string s2)
{
    int sz1=s1.size(), sz2=s2.size();
    if(sz1<sz2)
        while(sz1!=sz2)
        sz1++, s1="0"+s1;
    else
        while(sz1!=sz2)
        sz2++, s2="0"+s2;
    string res="";
    char dig;
    int rem=0, sum;
    for(int i=sz1-1;i>=0;i--)
    {
        sum=(s1[i]-'0')+(s2[i]-'0')+rem;
        rem=sum/10; dig=sum%10+'0';
        res=dig+res;
    }
    if(rem) res='1'+res;
    return res;
}
string diff(string s, string k)
{
    int sz1=s.size(), sz2=k.size();
    if(sz1<sz2)
        while(sz1!=sz2)
        sz1++, s="0"+s;
    else
        while(sz1!=sz2)
        sz2++, k="0"+k;
    int rem=0, sum;
    char dig;
    string res="";
    int sz=s.size();
    for(int i=sz-1;i>=0;i--)
    {
        sum=(s[i]-'0')-(k[i]-'0')-rem;
        if(sum<0)
        {
            sum=sum+10;
            rem=1;
        }
        else rem=0;
        dig=sum%10+'0';
        res=dig+res;
    }
    if(res[0]=='0')
        res=res.erase(0, 1);
    return res;
}
string mult1(string s1, int d)
{
    int sz=s1.size();
    int rem=0, sum;
    string res="";
    char dig;
    for(int i=sz-1;i>=0;i--)
    {
        sum=(s1[i]-'0')*d+rem;
        rem=sum/10; dig=sum%10+'0';
        res=dig+res;
    }
    if(rem)
    {
        dig=rem+'0';
        res=dig+res;
    }
    return res;
}
string mult2(string s1, string s2)
{
    int sz=s1.size();
    string res="0";
    int br=0;
    for(int i=s2.size()-1;i>=0;i--)
    {
        int dig=s2[i]-'0';
        string ss=mult1(s1, dig);
        for(int i=0;i<br;i++)
            ss=ss+"0";
        res=sum(res, ss);
        br++;
    }
    return res;
}

int main()
{
    int n;
    string k, l;
    cin>>n>>k;
    l=k;
    int szdiff=n-k.size();
    string s="1";
    for(int i=0;i<szdiff;i++)
        k+="0";
    for(int i=0;i<n-1;i++)
        s+="0";
    while(true)
    {
        string diff1=diff(k, l);
        if(s.size()>diff1.size()) break;
        k=diff1;
    }
    cout<<k<<endl;
    return 0;
}
