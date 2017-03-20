#include<iostream>
using namespace std;
#define MAXN 1000

string a;
long long stor[MAXN][2];
long long n,m;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>a;
    cin>>n>>m;
    if(n>=10)
    {
    for(int i=0;i<a.size();i++)
    {
        int t = (a[i]-'0');
        for(int j=0;j<n;j++) stor[j][0]=stor[j][1];
        for(int j=0;j<n;j++)
        {
            int ind = (((j*5)<<1)+t)%n;
            stor[ind][1]=stor[ind][1]+stor[j][0];
            if(stor[ind][1]>=m) stor[ind][1]-=m;
        }
        stor[t][1]++;
    }
    }
    else{
    for(int i=0;i<a.size();i++)
    {
        int t = (a[i]-'0')%n;
        for(int j=0;j<n;j++) stor[j][0]=stor[j][1];
        for(int j=0;j<n;j++)
        {
            int ind = (((j*5)<<1)+t)%n;
            stor[ind][1]=stor[ind][1]+stor[j][0];
            if(stor[ind][1]>=m) stor[ind][1]-=m;
        }
        stor[t][1]++;
    }
    }
    cout<<stor[0][1]%m<<endl;
    return 0;
}
