#include<iostream>
using namespace std;
int main()
{
    int a[1024],b[1024],n,k;
    cin>>k>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];
    }
    cout<<k/2<<endl;
    cout<<k+2<<" "<<a[n-3]<<" "<<b[n-3]<<" "<<a[n-4]<<" "<<b[n-4]<<" "<<a[n-5]<<" "<<a[n-1]<<" "<<a[n-11]<<" "<<b[n-11]<<" "<<a[n-6]<<" "<<b[n-5]<<endl;
    cout<<a[n-12]<<" "<<a[n-10]<<" "<<b[n-10]<<endl;
    cout<<a[n-12]<<" "<<a[n-12]<<" "<<b[n-12]<<endl;
    cout<<a[n-12]<<" "<<a[n-4]<<" "<<a[n-6]<<endl;
    return 0;
}
