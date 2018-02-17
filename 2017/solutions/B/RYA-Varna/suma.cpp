#include <iostream>
using namespace std;
int sum1[200000],sum2[200000],n;
int bins(int k)
{
    int mid,le=0,ri=n-1;
    while(le<=ri)
    {
        mid=(le+ri)>>1;
        if(sum1[mid]==k)return mid;
        else if(sum1[mid]<k)le=mid+1;
        else ri=mid-1;
    }
    return -1;
}
int main()
{
    int a[200000],i,ind,maxs=0;
    cin>>n;
    cin>>a[0];
    sum1[0]=a[0];
    for(i=1;i<n;i++)
    {
        cin>>a[i];
        sum1[i]=sum1[i-1]+a[i];
    }
    sum2[0]=sum1[n-1];
    for(i=1;i<n;i++)
    {
        sum2[i]=sum2[i-1]-a[i-1];
    }
    for(i=n-1;i>=1;i--)
    {
        ind=bins(sum2[i]);
        if(ind!=-1 && ind<i && (n+ind-i)>maxs)
        {
            maxs=n+ind-i+1;
        }
    }
    cout<<maxs<<endl;
}
