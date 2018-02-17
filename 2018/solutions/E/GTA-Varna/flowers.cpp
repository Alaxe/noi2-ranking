#include<iostream>
using namespace std;
int main ()
{
    long long n,nc[10000],q,maxc=-1,brp=0;
    long long i;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>nc[i];
        if(nc[i]>maxc)maxc=nc[i];
    }
    for(i=0; i<n; i++)
    {
        brp+=maxc-nc[i];
    }
    cin>>q;
    cout<<brp*q<<endl;
    return 0;
}
