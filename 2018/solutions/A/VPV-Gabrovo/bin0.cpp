#include<iostream>
using namespace std;
int a[10000][10000];
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long s,t,z;
    cin>>s>>t>>z;
    s--;
    if(t==1 and z==0){cout<<1<<endl;return 0;}
    if(t==1){cout<<0<<endl;return 0;}

    long long maxt=-1;
    long long t1=1;
    while(t1<=t)
    {
        maxt++;
        t1*=2;
    }
    long long maxs=0;
    long long s1=1;
    long long fl=0;
    while(s1<s)
    {
        maxs++;
        s1*=2;
        if(s1==s)fl=1;
    }
    a[1][1]=1;
    for(long long i=2;i<=maxt+1;i++)
        for(long long j=1;j<=i;j++)
            a[i][j]=a[i-1][j]+a[i-1][j-1];

     long long ans=0;

     string ss="";
     while(s>0)
     {
         if(s%2==0)ss="0"+ss;
         else ss="1"+ss;
         s/=2;
     }
     string tt="";
     while(t>0)
     {
         if(t%2==0)tt="0"+tt;
         else tt="1"+tt;
         t/=2;
     }
    long long z1=z;

    long long ns=ss.size();
    long long nt=tt.size();
    //cout<<ns<<" "<<ss<<endl<<nt<<" "<<tt<<endl;
    for(long long i=nt;i>=1;i--)
        ans=ans+a[i][z+1];
        //cout<<ns<<endl;
    for(long long i=ns;i>=1;i--)
        ans=ans-a[i][z+1];
        //cout<<ans<<endl;
    long long pos=0;
    for(long long i=0;i<nt;i++)
    {

        if(tt[i]=='1')
        {
            pos=i;
        }
    }
    for(long long i=0;i<pos+1;i++)
    {

        if(tt[i]=='0')
        {
            if(nt-i>=0 and z+1>=0)ans=ans-a[nt-i][z+1];z--;
        }
        //cout<<i<<" : "<<nt-i<<" "<<z+1<<"  :  "<<a[nt-i][z+1]<<" and = "<<ans<<endl;
    }
    for(long long i=0;i<ns;i++)
    {

        if(ss[i]=='1')
        {
            pos=i;
        }
    }
    for(long long i=0;i<pos+1;i++)
    {

        if(ss[i]=='0')
        {

            if(ns-i>=0 and z1+1>=0)ans=ans+a[ns-i][z1+1];z1--;
        }
        //cout<<i<<" : "<<ns-i<<" "<<z1+1<<"  :  "<<a[ns-i][z1+1]<<" and = "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
