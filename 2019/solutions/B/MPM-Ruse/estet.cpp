#include<iostream>
using namespace std;
long long n,a[100005];
long long lf[100005],res=1000000;
/*void solve(long long curr,long long removed)
{
    if(curr==n)
    {
        
    }
}*/
int main()
{
    long long i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        lf[a[i]]=i;
    }
    cout<<n*3/4<<endl;
    //solve(1,0);
}
