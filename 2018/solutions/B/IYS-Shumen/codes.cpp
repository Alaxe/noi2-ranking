#include <bits/stdc++.h>
using namespace std;
vector<string> Generate(vector<string>prev, vector<char> digits)
{
    vector<string >next;
    for(int i=0;i<digits.size();i++)
        if(!i%2)
            for(int j=0;j<prev.size();j++)
                next.push_back(digits[i]+prev[j]);
        else 
            for(int j=prev.size()-1;j>=0;j--)
                next.push_back(digits[i]+prev[j]);
    return next;
}
vector<long long >ans;
long long tr(string s)
{
    long long i,sz=s.size(),sum=0;
    for(i=0;i<sz;i++)
    {
        sum+=s[i]-'0';
    }
    return sum;
}
int main()
{
    long long  n,k,a,b,i,j;
    vector<string>v;
    vector<char>h;
    char c;
    string s;
    cin>>n>>k>>a>>b;
    for(i=0;i<n;i++)
    {
        cin>>c;
        s=c;
        v.push_back(s);
        h.push_back(c);
    }
    vector<string>t;
    t=v;
    for(i=1;i<k;i++)
    {
        t=Generate(t,h);
    }
    a--;
    b--;
    long long mx=0;
    string maxx="0";
    for(i=a;i<=b;i++)
    {
        if(t[i]>maxx)
        {
            maxx=t[i];
        }
        if(i!=b)
        mx=max(abs(tr(t[i])-tr(t[i+1])),mx);
    }
    cout<<maxx<<" "<<mx<<endl;;
    
return 0;
}