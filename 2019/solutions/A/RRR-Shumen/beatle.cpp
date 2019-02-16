#include<iostream>
using namespace std;
int main()
{
    int a[1024],b[1024],c[1024],d[1024],n,k;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    cin>>k;
    for(int i=0; i<k; i++)
    {
        cin>>d[i];
    }
    cout<<d[0]<<" "<<d[0]<<" "<<d[0]*2<<" "<<d[0]*2<<" "<<d[0]<<endl;
    return 0;
}
