#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

bool a[50];

long long pr[50];

void fact(long long n)
{
    int del[50]={0}, i=2;
    while(n>1)
    {
        while(n%i==0)
        {
            n/=i;
            del[i]++;
        }
        i++;
    }
    for(int j=0; j<50; j++)
    {
        if(pr[j]<del[j]) pr[j]=del[j];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int ch;
        cin>>ch;
        a[ch]=1;
    }
    for(int i=0; i<50; i++)
    {
        if(a[i]) fact(i);
    }
    long long res=1;
    for(long long i=0; i<50; i++)
    {
        if(pr[i]%2) pr[i]++;
        pr[i]/=2;
        for(int p=0; p<pr[i]; p++) res*=i;
    }
    cout<<res<<endl;
    return 0;
}
