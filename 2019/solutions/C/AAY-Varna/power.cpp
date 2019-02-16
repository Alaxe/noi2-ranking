#include<bits/stdc++.h>
using namespace std;
int a[1000];
void func(int s)
{
    while(s%2==0){a[2]++;s/=2;}
    for(int i=3;i<=s;i+=2)
    {
        while(s%i==0)
        {
            a[i]++;
            s/=i;
        }
    }
}
int main()
{
    int n,k,s;
    long long res=1;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        func(s);
    }
    for(int i=2;i<=43;i++)
    {
        for(int j=1;j<=(a[i]/k);j++)
        {
            res*=i;
        }
        if(a[i]%k)res*=i;
    }
    cout<<res<<endl;
}
