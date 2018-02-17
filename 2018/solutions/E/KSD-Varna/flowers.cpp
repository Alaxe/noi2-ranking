#include<iostream>
using namespace std;
int main()
{
    unsigned long long n,q,a[10000],br=0,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>q;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j]) swap(a[i],a[j]);
        }
    }
    m=a[n-1];
    for(int i=0;i<n;i++)
    {
        while(a[i]<m)
        {
            br++;
            a[i]++;
        }
    }
    cout<<br*q<<endl;
    return 0;
}
