#include<iostream>
using namespace std;
int main()
{
    int n,vm,k,v[10000],i,maxi=0,sum=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>vm;
        if(vm>maxi)maxi=vm;
        v[i]=vm;
    }
    cin>>k;
    for(i=0;i<n;i++)
    {
        sum+=(maxi-v[i])*k;
    }
    cout<<sum<<endl;
    return 0;
}
