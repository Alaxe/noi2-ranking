#include<iostream>
using namespace std;
long long k,m,a[999999],i,sum=0,br=0;
int main()
{
cin>>k>>m;
for(i=0;i<k;i++)
{
    cin>>a[i];
    br++;
    if(a[i]%2==0)sum+=a[i];
      if(sum>=m || a[i]==200)
      {
          if(sum-m>m-(sum-a[i]))
          {
              if(br==1)cout<<br<<" "<<sum<<endl;
              else cout<<i<<" "<<sum<<endl;
          }
          else cout<<i+1<<" "<<sum<<endl;
          break;
      }

}

}
