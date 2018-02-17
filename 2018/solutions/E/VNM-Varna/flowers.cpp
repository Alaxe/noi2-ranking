#include<iostream>
using namespace std;
int main()
{
    long long n, a[10000], q, m=0, sb=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        sb+=a[i];
        if(a[i]>m) m=a[i];
    }
    cin>>q;
    cout<<(n*m-sb)*q<<endl;
    return 0;
}
