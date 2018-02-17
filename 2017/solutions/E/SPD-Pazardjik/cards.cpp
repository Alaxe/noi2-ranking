#include <iostream>
using namespace std;
int main()
{
    int n,a[1000],b[1000],pr[1000],cntr=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++)
    {
        pr[i]=a[i]*b[i];
        for(int k=i+1;k<n;k++)
            if(pr[k]<=pr[i]) cntr++;
    }
    cout<<cntr<<endl;
    return 0;
}
