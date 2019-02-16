#include<bits/stdc++.h>
using namespace std;
long long prime[20]={2,3,5,7,11,13,17,19,23,29,31,37,41};
long long pbr[20];
long long n,k,a,c=1;
void funk(long long l)
{
    int no=0;
    for(long long i=0;i<13;i++)
    {
        no=0;
        while(l%prime[i]==0)
        {
            no++;
            l/=prime[i];
        }
        if(no>pbr[i])pbr[i]=no;
        if(l==1)return;
    }
}
int main()
{
    cin>>n>>k;
    for(long long i=0;i<n;i++)
    {
        cin>>a;
        funk(a);
    }
    for(long long i=0;i<13;i++)
    {
        if(pbr[i]%k!=0)pbr[i]=pbr[i]/k+1;
        else pbr[i]/=k;
        for(long long j=0;j<pbr[i];j++)
        {
            c*=prime[i];
        }
    }
    cout<<c<<endl;
}
/**
4 3
3 4 5 6

42 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42
*/
