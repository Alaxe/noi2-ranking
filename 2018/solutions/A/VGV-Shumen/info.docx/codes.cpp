#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
vector<string> gen(vector<string>prev,vector<char>digits)
{
    vector<string>next;
    for(int i=0;i<digits.size();i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<prev.size();j++)
            {
                next.push_back(digits[i]+prev[j]);
            }
        }
        else
        {
            for(int j=prev.size()-1;j>=0;j--)
            {
                next.push_back(digits[i]+prev[j]);
            }
        }
    }
    return next;
}
bool comp(string s1,string s2)
{
    if(s1.size()==s2.size())return s1>s2;
    return s1.size()>s2.size();
}
int sumc(string s)
{
    int to_return=0;
    for(int i=0;i<s.size();i++)
    {
        to_return+=int(s[i]-'0');
    }
    return to_return;
}
int main()
{
int n,k,a,b;
vector<char>digits;
vector<string>prev;
cin>>n>>k>>a>>b;
for(int i=0;i<n;i++)
{
    char c;
    cin>>c;
    digits.push_back(c);
    string s="";
    s+=c;
    prev.push_back(s);
}
for(int i=2;i<=k;i++)
{
    prev=gen(prev,digits);
}
int maxs=0;
string maxch="";
for(int i=a-1;i<b;i++)
{
    if(!comp(maxch,prev[i]))maxch=prev[i];
    if(i!=a-1)
    {
        int curr=abs(sumc(prev[i-1])-sumc(prev[i]));
        if(curr>maxs)maxs=curr;
    }
}
cout<<maxch<<" "<<maxs<<endl;
return 0;
}
