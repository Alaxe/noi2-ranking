#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],b[n],i,br=0;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        cin>>b[i];
    }
    for(i=0; i<=n; i++)
    {
        if(a[i+1]>=a[i] && b[i+1]>=b[i] && a[i+1]>=b[i] && b[i+1]>=a[i])
        {
            br++;
        }
    }
    cout<<br;
    return 0;
}
