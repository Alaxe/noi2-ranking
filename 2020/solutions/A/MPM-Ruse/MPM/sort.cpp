#include<iostream>
using namespace std;
long long n,i,a[100005],res=0;
int main()
{
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    
    for(i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            res=a[i-1]-a[i];
        }
    }
    
    cout<<res<<endl;
    return 0;
}
