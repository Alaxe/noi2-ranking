#include <iostream>
#include <cstdio>
#include<string>
using namespace std;
string s;
int sz;
long long int br;
bool a[16];
void Read()
{
    cin>>s;
    sz=s.size();
}
void Solve()
{
    string x;
    for(int i=0;i<sz;i++)
    {
        if(a[i]!=0)
        {
            x+=s[i];
        }
    }
    for(int i=0;i<x.size();i++)
    {
        if(x[i]!=x[x.size()-i-1]) return;
    }
    br++;
    br%=1000000007;
}
void Req(bool a[],int curr)
{
    if(curr<sz)
    {
        for(int i=0;i<2;i++)
      {
        a[curr]=i;
        Req(a,curr+1);
      }
    }
    if(curr==sz) Solve();
}
int main()
{
    Read();
    Req(a,0);
    cout<<br-1<<endl;
    return 0;
}
