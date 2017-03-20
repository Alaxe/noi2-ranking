#include<iostream>
using namespace std;
long long k,m,a[999999],i,sum=0;
int main()
{
cin>>k>>m;
for(i=0;i<k;i++)
{
    cin>>a[i];
    if(a[i]%2==0)sum+=a[i];
      if(sum>=m)
      {
          if(sum-m>m-(sum-a[i]))
          {
             cout<<i+1<<" ";
             if(sum-a[i]>=m)cout<<sum-a[i]<<endl;



          }
          else cout<<i+1<<" "<<sum<<endl;
          break;
      }

}

}
