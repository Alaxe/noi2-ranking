#include<iostream>
using namespace std;
long long dp[4000001],answer;
void downtoup(int x)
{
    int i;
    for(i=0;i<1048576*2;i++)
    {
        if(dp[i-x]&&!dp[i])
        {
            dp[i]=true;
            answer++;
        }
    }
}
void uptodown(int x)
{
    int i;
    for(i=2009999;i>=x;i--)
    {
        if(dp[i-x]&&!dp[i])
        {
            dp[i]=true;
            answer++;
        }
    }
}
int main()
{
    long long n,a[1024],sum=0,i,ts=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int rr;
        cin>>rr;
        if(rr>0)uptodown(rr);
        if(rr<0)downtoup(rr);
        if(!dp[rr+1000000])
        {
            dp[rr+1000000]=true;
            answer++;
        }
    }
   
    cout<<answer<<endl;
    return 0;
}