#include <bits/stdc++.h>
using namespace std;
long long  e[16372],n;
vector<long long >v;
void eratosten(long long  tek)
{
    long long  i,j;
    e[1]=2;
    for(j=2; j<tek; j+=2)
    {
        e[j]=2;
    }
    for(i=3; i<tek; i++)
    {
        if(!e[i])
        {
            e[i]=1;
            v.push_back(i);
            for(j=i*2; j<tek; j+=i)
            {
                e[j]=2;
            }
        }
    }
}

bool composite(long long  x)
{
    long long  i;
    if(x%2==0)return true;
    for(i=0;i<v.size();i++)
    {
        if(x%v[i]==0&&x!=v[i])return true;
    }
    return false;
}
bool solve(long long  tek)
{
    long long  i;
    for(i=0; i<v.size(); i++)
    {
        if(!composite(v[i]*v[i]+tek))return false;
    }
    return true;
}
int main()
{
    long long  i,j,cnt=0,t,r=1;
    cin>>n;
    t=n;
    eratosten(10000);
    while(t)
    {
        r*=10;
        t/=10;
    }
    r*=10;
    for(j=n+(n%2); j<r; j+=2)
    {
        if(solve(j)){cout<<j<<endl;return 0;}
    }
    cout<<0<<endl;
    return 0;
}
