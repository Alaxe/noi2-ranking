#include<iostream>
using namespace std;
int main()
{
    int n,a[10000],max=0;
    unsigned long long k,s=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]>max)max=a[i];
    }
    cin>>k;
    for(int i=0; i<n; i++)
    {
        s+=(max-a[i])*k;
    }
    cout<<s<<endl;
    return 0;
}
