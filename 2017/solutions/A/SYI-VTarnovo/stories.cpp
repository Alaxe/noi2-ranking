#include<iostream>
using namespace std;
unsigned long long k,n,first,mul,add,mod,story[10000000],sum,asd,days=1;

void sumStories()
{
    story[0]=first;
    for(int i=1;i<n;i++)
    {
        story[i]=(story[i-1]*mul+add)%mod;
        //cout<<story[i]<<endl;

    }
}

int maxGrade(int i, int j)
{
    unsigned long long m;
    int q=j-i+1;
    m=story[i];
    for(i=i+1;i<=j;i++)
        if(m<story[i])m=story[i],q=j-i+1;
    days=q;
    return m;
}

void solv()
{
    sum+=first;
    unsigned long long maxF=first;
    for(int i=1;i<n;i++)
    {
        days++;
        if(maxF<story[i])maxF=story[i],days=1;
        if(days>k)
        {
            maxF=maxGrade(i-k+1,i);
        }
        sum+=maxF;
    }
    cout<<sum<<endl;
}

int main()
{
    cin>>n>>k;
    cin>>first>>mul>>add>>mod;
    sumStories();
    solv();
}
/*
            133742 666
            20 3 17 1000000007

*/


