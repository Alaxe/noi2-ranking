#include<iostream>
using namespace std;
int main()
{
    int M,K,a[100001],sum=0,nbch=0,i=1;
    int k=0;
    cin>>M>>K;
    cin>>a[0];
    nbch=a[0];
    if(a[0]%2==0)sum=a[0];
    k=1;
    if(a[0]>K)
    {
        cout<<k<<" "<<sum<<"\n";
        return 0;
    }
    if(a[i]%2==0)sum+=a[i];
    while(1)
    {
        cin>>a[i];
        if(M-a[i]<=nbch)
        {
            nbch=a[i];
            k=i;
        }
        if(a[i]%2==0)sum+=a[i];
        if(sum>K || i==200)break;
        i++;
    }
    cout<<k<<" "<<sum<<"\n";
    return 0;
}
