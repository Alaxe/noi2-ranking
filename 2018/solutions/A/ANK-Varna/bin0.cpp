#include<bits/stdc++.h>
using namespace std;
long long m[64] [64];
long long s,t;
bool dv[64];
bool dv1[64];
long long z;
long long f(long long n)
{
    //memset(dv,sizeof(dv),0);
//memset(dv,sizeof(dv1),0);

    long long br=0;
    long long s=0;
    bool flag;
    for(long long i=0; i<64; i++)
    {
        //cout<<i<<endl;
        dv[i]=n%2;
        ///if(dv[i]==0) flag=1;
        // cout<<dv[i];
        n/=2;
        if(n==0) break;
        br++;

    }
    //cout<<br<<endl;
    /// if(flag==0) return m[br][z];

    flag=0;

    for(long long i=0; i<br+1; i++)
    {
        dv1[i]=dv[br-i];
        // cout<<dv1[i];

    }
    //cout<<endl;
    for(long long i=0; i<br; i++)
    {
        s+=m[i] [z];
    }
   // cout<<s<<endl;
    dv1[0]=0;
    for(long long i=1; i<=br; i++)
    {
        if(i==br)
        {
            if(dv1[i]==0)
            {
                z--;
                if(z==0) s++;
            }
        }
        if(dv1[i]==0)
        {
            z--;
            continue;
        }
        //  cout<<i<<endl;
         if(dv1[i-1]==0&&i==br) z=1;
        if(dv1[i-1]==0)  {s+=m[br-i][z-1]; /*cout<<m[br-i] [z-1]<<endl;*/}
        else {s+=m[br-i] [z-1]; /*cout<<br-i<<" "<<z-1<<" "<<br<<endl;*/}
        //  s+=m[br][z];
        // cout<<s<<endl;
    }
    return s;

}

int main()
{
    z=2;
cin>>s>>t>>z;
    m[0] [0]=1;
    m[0] [1]=0;
    m[1] [0]=1;
    m[1] [1]=1;
    for(long long i=2; i<62; i++)
    {
        m[i] [0]=1;
        for(long long j=1; j<=i; j++)
        {
            m[i] [j]=m[i-1] [j-1]+m[i-1] [j];
        }
    }
    // cin>>s>>t>>z;
    long long ans1=f(s-1);
    long long ans2=f(t);
  //  cout<<f(11)<<endl;
  cout<<ans2-ans1<<endl;
    //cout<<f(t)-f(s-1)<<endl;
    return 0;
}
