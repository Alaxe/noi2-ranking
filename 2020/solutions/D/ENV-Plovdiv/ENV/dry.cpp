#include<bits/stdc++.h>
using namespace std;
int main()
{
long long n,u,v,i,sum=0,j,maxx=0,max1=0;
cin>>n>>u>>v;
long long a[n];
for(i=0;i<n;i++)
{
    cin>>a[i];
}
for(i=0;i<n;i++)
{
    if(a[i]<=a[i+1])
    {
        sum=sum+a[i]*u*v;//cout<<sum<<" "<<a[i]<<" "<<a[i+1];
        if(i+1==n-1) break;
    }
    else
    {a[i+1]=max1;
      for(j=i+1;j<n;j++)
      {
          if(a[j]>=max1) {max1=a[j];maxx=j;}
      }//cout<<max1<<endl;
      if(a[i]<=max1)
      {
          sum=sum+a[i]*(maxx-i)*u*v;
          if(maxx==n-1) break;
      }
      else {sum=sum+a[maxx]*(maxx-i)*u*v;if(maxx==n-1) break;}
    }
}
cout<<sum<<endl;
return 0;
}
