#include<bits/stdc++.h>
using namespace std;
struct tri
{
    long long  x,y,z;
    tri(){};
    tri(long long  a,long long  b,long long  c)
    {
        x=a;
        y=b;
        z=c;
    }
    bool operator<(const tri &t)const
    {
        if(x==t.x)
        {
            if(y==t.y)return z<t.z;
            return y<t.y;
        }
        return x<t.x;
    }
};
const int MAX = (int)(1<<21);
const int MAXN = (int)(1<<17);
map< tri ,int>mp;
long long MOD[3]={int(1e9+7),int(1e9+9),int(1e7+9)};
long long base[3]={11,13,17};
long long cn[MAX],m,n,w,k;
long long a[MAXN],b[MAXN],ans;
void solveez()
{
    long long  br=1,i;
    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
            br++;
        else
        {
            if(br>=k)cn[a[i-1]]=br-k+1;
            br=1;
        }
    }
    if(br>=k)cn[a[n-1]]=br-k+1;
    br=1;
    for(i=1;i<m;i++)
    {
        if(b[i]==b[i-1])
            br++;
        else
        {
            if(br>=k)
            {
                ans+=cn[b[i-1]]*(br-k+1);
            }
            br=1;
        }
    }
    if(br>=k)ans+=cn[b[m-1]]*(br-k+1);
    cout<<ans<<endl;
}
void solvehard()
{
    int beg=0;
    long long h[3]={0,0,0};
    long long pw1=1,pw2=1,i,pw3=1;
    for(i=1;i<k;i++){pw1*=base[0];pw1%=MOD[0];pw2*=base[1];pw2%=MOD[1];pw3*=base[2];pw3%=MOD[2];}
    for(i=0;i<n;i++)
    {
        if(i-beg>=k)
        {
            h[0]+=MOD[0]-a[i-k]*pw1;
            h[0]%=MOD[0];
            h[1]+=MOD[1]-a[i-k]*pw2;
            h[1]%=MOD[1];
            h[2]+=MOD[2]-a[i-k]*pw3;
            h[2]%=MOD[2];
        }
        h[0]*=base[0];
        h[0]+=a[i];
        h[0]%=MOD[0];
        h[1]*=base[1];
        h[1]+=a[i];
        h[1]%=MOD[1];
        h[2]*=base[2];
        h[2]+=a[i];
        h[2]%=MOD[2];
        //cout<<h[0]<<" "<<h[1]<<endl;
        if(i!=0&&a[i]<a[i-1])
        {
            h[0]=h[1]=h[2]=a[i];
            beg=i;
        }
        if(i-beg+1>=k)
        {mp[{h[0],h[1],h[2]}]++;}
    }
    h[0]=h[1]=h[2]=0;
    beg=0;
    for(i=0;i<n;i++)
    {
        if(i-beg>=k)
        {
            h[0]+=MOD[0]-b[i-k]*pw1;
            h[0]%=MOD[0];
            h[1]+=MOD[1]-b[i-k]*pw2;
            h[1]%=MOD[1];
            h[2]+=MOD[2]-b[i-k]*pw3;
            h[2]%=MOD[2];
        }
        h[0]*=base[0];
        h[0]+=b[i];
        h[0]%=MOD[0];
        h[1]*=base[1];
        h[1]+=b[i];
        h[1]%=MOD[1];
        h[2]*=base[2];
        h[2]+=b[i];
        h[2]%=MOD[2];
        //cout<<h[0]<<" "<<h[1]<<endl;
        if(i!=0&&b[i]<b[i-1])
        {
            h[0]=h[1]=h[2]=b[i];
            beg=i;
        }
        if(i-beg+1>=k)
        {ans+=mp[{h[0],h[1],h[2]}];}
    }
    cout<<ans<<endl;
}
void read()
{
    int i,j;
    cin>>w>>k;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    cin>>m;
    for(i=0;i<m;i++)cin>>b[i];
    if(w==2)
        solveez();
    else solvehard();
}
int main()
{
    read();
    return 0;
}
/*
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6
*/
