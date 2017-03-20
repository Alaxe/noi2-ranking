#include<iostream>
#include<cstring>
using namespace std;
long long used[1024];
long long d[1024];
int main()
{
    long long n,m;
    string s;
    cin>>s;
    cin>>n>>m;
    int i,j;
    int sz=s.size();
    for(i=0;i<sz;i++)
        s[i]-='0';
    int sum=0;
    used[s[0]%n]++;
    d[s[0]%n]++;
    int dd=10%n;
    int x,y;
    for(i=1;i<sz;i++)
    {
        for(j=0;j<n;j++)
        {
            if(!used[j]) continue;
            d[(j*dd+s[i]%n)%n]+=used[j];
            d[(j*dd+s[i]%n)%n]%=m;
        }
        d[s[i]%n]++;
        d[s[i]%n]%=m;
        for(j=0;j<n;j++)
        {
            used[j]=d[j];
        }
    }
    cout<<used[0]<<endl;
    return 0;
}
