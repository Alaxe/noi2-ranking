#include<iostream>
using namespace std;

int countZeros(long long i)
{
    int rt=0;
    while(i!=0)
    {
        if(i%2==0)rt++;
        i/=2;
    }
    return rt;
}

int pow(long long a)
{
    int rt=0;
    while(a!=0)
    {
        a/=2;
        rt++;
    }
    return rt;
}

long long fact(int n)
{
    long long rt=1;
    for(int i=1;i<=n;i++)
        rt*=i;
    return rt;
}

long long pow2(int a)
{
    long long rt=1;
    for(int i=1;i<=a;i++)
        rt*=2;
    return rt;
}

long long sumOfCombs(int n,int z)
{
    if(z==0)return n;
    long long f=fact(z);
    long long ans=0;
    for(int i=z;i<=n;i++)
    {
        long long cur=1;
        for(int j=i;j>=i-z+1;j--)
            cur*=j;
        ans=ans+(cur/f);
    }
    return ans;
}

long long findAns(long long f, int z)
{
    int highestPower=pow(f);
    long long rt=sumOfCombs(highestPower-2, z);
    long long s=pow2(highestPower-1);
    for(long long i=s; i<=f; i++)
    {
        if(countZeros(i)==z)rt++;
    }
    return rt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long s,t;
    int z;
    long long ans=0;
    cin>>s>>t>>z;
    long long answerT=findAns(t,z);
    long long answerS=findAns(s,z);
    if(countZeros(s)==z)
    {
        cout<<answerT-answerS+1<<endl;
    }
    else
    {
        cout<<answerT-answerS<<endl;
    }
    /*for(long long i=s;i<=t;i++)
    {
        int cnt0=countZeros(i);
        if(cnt0==z)ans++;
        //cout<<i<<" "<<cnt0<<endl;
    }
    cout<<ans<<endl;*/
    return 0;
}
/*
10000000 20000000 2
*/
