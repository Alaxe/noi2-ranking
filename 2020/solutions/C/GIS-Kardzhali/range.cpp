#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[100001],x,y,br[100001]={0},k=0;
int main()
{
cin>>n;
for(int i=0;i<n;i++)
cin>>a[i];
cin>>m;
sort(a,a+n);
    for(int i=0;i<m;i++)
    {
    cin>>x>>y;
            while(a[k]<=y&&k!=n)
            {
            if(a[k]>=x)br[i]++;
            k++;
            }
    k=0;
    }
for(int i=0;i<m;i++)
cout<<br[i]<<endl;
}
