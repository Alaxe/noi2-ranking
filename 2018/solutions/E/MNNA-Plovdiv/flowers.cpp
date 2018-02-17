#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n,q,i,k,maxi=0,sum=0,br=0,ob,sum1=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>k;
        br++;
        if(k>maxi) maxi=k;
        sum+=k;
    }
    cin>>q;
    sum1=maxi*n;
    ob=(sum1-sum)*q;
    cout<<ob<<endl;
    return 0;
}
