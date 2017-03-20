#include<bits/stdc++.h>
using namespace std;
int main()
{int aa[1000],bb[1000],n,j,a[1000],b[1000],i=0,t;
while(cin>>a[i]>>b[i])i++;
n=i;
for(j=0;j<n;j++)
for(i=0;i<n;i++)if(a[i]>a[j]){swap(a[i],a[j]);swap(b[i],b[j]);}
t=a[0];
for(i=0;i<n;i++){aa[i]=a[i];bb[i]=b[i];}
for(i=0;i<n-1;i++)
{t+=b[i];
if(t<a[i+1])t=a[i+1];
else a[i+1]=t;
}
cout<<t+bb[n-1]-aa[n-1]<<endl;
return 0;
}
