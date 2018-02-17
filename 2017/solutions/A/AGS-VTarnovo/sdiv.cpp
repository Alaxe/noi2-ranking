#include <iostream>
#include <algorithm>
using namespace std;

bool a[1024];

string s;

long long n,m,ans=0;

long long check()
{
    long long k=0;
    for(int i=0;i<s.size();i++)
    {
        if(a[i]==1)
        {
            k=k*10+s[i]-'0';
        }
    }
    if(k%n==0)ans++;
}

void func(bool x,int k)
{
    a[k]=x;
    if(k+1==s.size())check();
    else
    {
        func(0,k+1);
        func(1,k+1);
    }
}


int main()
{
    cin>>s;
    cin>>n>>m;
    if(s.size()>18)
    {
        cout<<0<<endl;
        return 0;
    }
    func(0,0);
    func(1,0);
    cout<<(ans-1)%m<<endl;
}
