#include<iostream>
#include<math.h>
using namespace std;
   int main()
{int X,Y,n,t,i;double x[11000],y[11000],w[11000],h[11000],g[11000],f[11000],s[11000],a[11000],b[11000];
cin>>X>>Y;
cin>>n;
for( i=0;i<=n-1;i++)
    {cin>>x[i];
     cin>>y[i];
     cin>>w[i];
     cin>>h[i];
	}
cin>>t;
for( i=0;i<=t-1;i++)
    {cin>>g[i];
     cin>>f[i];
	}
for( i=0;i<=n-1;i++)
 
 {if((x[i]+w[i]<=X)&&(y[i]+h[i]<=h[i]))
   {
    a[i]=fabs(w[i]-x[i]);
    b[i]=fabs(h[i]-y[i]);
   }
 }
   for(i=0;i<=n-1;i++)
   if((g[i]>=x[i])&&(f[i]>y[i])&&(g[i]<=w[i]-x[i])&&(f[i]<=h[i]-y[i]))
   s[i]=a[i]*b[i];
for( i=0;i<=n-1;i++)
   cout<<s[i];
   cout<<endl;
}
   
   

