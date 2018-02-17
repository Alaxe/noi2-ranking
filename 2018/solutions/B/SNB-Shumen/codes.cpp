#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<string> generate(vector<string>prev, vector<char>digits)
{
    vector<string>next;
    int i,dz,j,sz;
    dz=digits.size();
    for(i=0;i<dz;i++)
    {
        if(i%2==0)
        {
            sz=prev.size();
            for(j=0;j<sz;j++)
            {
                next.push_back(digits[i]+prev[j]);
            }
        }
        else
        {
            for(j=sz-1;j>=0;j--)
            {
                next.push_back(digits[i]+prev[j]);
            }
        }
    }
    return next;
}
string Dig_sum(string x)
{
    long long sz,i;
    string s="";
    long long t=0;
    char c;
    sz=x.size();
    for(i=1;i<sz;i++)
    {
        t+=((x[i-1]-'0')+(x[i]-'0'));
    }
    while(t)
    {
        c=t%10+'0';
        t/=10;
        s=c+s;
    }
    return s;
}
void add_zero(string &x,long long n)
{
    long long i;
    char c='0';
    for(i=0;i<n;i++)
        x=c+x;
    return ;
}
string Big_minus(string s,string x)
{
    long long sz1,sz2,i,a,b,t=0,o,p;
    char c;
    string ans="";
    sz1=s.size();
    sz2=x.size();
    if(sz1>sz2)add_zero(x,sz1-sz2);
    else if(sz1<sz2)add_zero(s,sz2-sz1);
    if(s==x)return 0;
    if(s>x)
    {
        for(i=sz1-1;i>=0;i--)
        {
            o=s[i]-'0';
            p=x[i]-'0';
            a=o-p-t;
            if(a<0){a=10+o-p-t;t=1;}
            else t=0;
            c=a+'0';
            ans=c+ans;
        }
    }
    else if(s<x)
    {
        for(i=sz2-1;i>=0;i--)
        {
            p=s[i]-'0';
            o=x[i]-'0';
            a=o-p-t;
            if(a<0){a=10+o-p-t;t=1;}

            else t=0;
            c=a+'0';
            ans=c+ans;
        }
    }
    while(ans[0]=='0')
    {
        ans.erase(0,1);
    }
    return ans;
}
void solve(vector<string>v,long long i,long long n)
{
    vector<string>sv;
    long long sz;
    string s=v[i];
    string t;
    string x="";
    sv.push_back(Dig_sum(v[i]));
    i++;
    for(i;i<=n;i++)
    {
        if(s<v[i])s=v[i];
        sv.push_back(Dig_sum(v[i]));
    }
    sz=sv.size();
    for(i=1;i<sz;i++)
    {
        t=Big_minus(sv[i-1],sv[i]);
        if(x<t)x=t;
    }
    cout<<s<<" "<<x<<endl;
}
int main()
{
    string s;
    vector<char>digits;
    vector<string>v;
    int n,k,i,sz;
    long long A,B;
    char c;
    cin>>n>>k>>A>>B;
    for(i=0;i<n;i++)
    {
        cin>>c;
        digits.push_back(c);
        s=c;
        v.push_back(s);
    }
    for(i=1;i<k;i++)
    {
        v=generate(v,digits);
    }
    solve(v,A-1,B-1);
	return 0;
}
/*
3 2 3 5
7 1 5
*/
