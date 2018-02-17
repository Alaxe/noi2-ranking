#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long n,k,a,b,i,maxr=0;
string maxi="",m="0";
char p;
vector<char>d;
vector<string>s;
vector<long long>r;

vector<string> generate(vector<string> prev, vector<char> digits)
{
    vector<string>next;
    for(int t=0;t<digits.size();t++)
    {
        if(t%2==0)
        {
            for(int j=0;j<prev.size();j++)
            {
                next.push_back(digits[t]+prev[j]);
            }
        }
        else
        {
            for(int j=prev.size()-1;j>=0;j--)
            {
                next.push_back(digits[t]+prev[j]);
            }
        }
    }
    return next;
}

long long digitsum(string x)
{
    int h;
    long long ret=0;
    for(h=0;h<x.size();h++)ret+=x[h]-'0';
    return ret;
}
int main()
{
    cin>>n>>k>>a>>b;
    for(i=0;i<n;i++){cin>>p;d.push_back(p);m[0]=p;s.push_back(m);}
    k--;
    for(i=0;i<k;i++)s=generate(s,d);
    maxi=s[a-1];
    r.push_back(digitsum(s[a-1]));
    for(i=a;i<b;i++)
    {
        if(s[i]>maxi)maxi=s[i];
        r.push_back(digitsum(s[i]));
    }
    
    for(i=0;i<r.size()-1;i++)
    {
        if(abs(r[i]-r[i+1])>maxr)maxr=abs(r[i]-r[i+1]);
    }
    cout<<maxi<<' '<<maxr<<endl;
    return 0;
}