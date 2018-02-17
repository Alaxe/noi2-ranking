#include<iostream>
using namespace std;
int n,k,first,mul,add,mod;
long long int a[10000000];
void Read()
{
    cin>>n>>k;
    cin>>first>>mul>>add>>mod;
    a[0]=first;
}
int Srsh(int x,int y)
{
    int i,maxx=0,z;
    for(i=x;i<=y;i++)
    {
       if(a[i]>=maxx)
       {
           maxx=a[i];
           z=i;
       }
    }
    return z;
}
void Resh()
{
    long long int i,sum=0,maxx,br=0;
    int z;
    maxx=first;
    sum+=maxx;
    br++;
    for(i=1;i<n;i++)
    {
        a[i]=((a[i-1]*mul)%mod+add%mod)%mod;
        if(a[i]>=maxx)
        {
            maxx=a[i];
            br=0;
        }
        if(br==k)
        {
            z=Srsh(i-k+1,i);
            maxx=a[z];
            br=i-z;
        }
        sum+=maxx;
        br++;
    }
    cout<<sum<<endl;
}
int main()
{
Read();
Resh();
return 0;
}
