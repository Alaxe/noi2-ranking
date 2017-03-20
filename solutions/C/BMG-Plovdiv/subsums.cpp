//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

 long long a[1002],sums[10000001],used[10000001];
int main ()
{
 int n;
 cin>>n;
 for(int i=0;i<n;i++) cin>>a[i];
 long long k=0;
 //sort(a,a+n);
 sums[k]=a[k];
 used[sums[k]]=1;
 k++;
 for(int i=1;i<n;i++)
 {
  sums[k]=a[i];k++;
  long long p=k;
  for(int j=0;j<p-1;j++)
  {
 long long t=a[i]+sums[j];
   if(used[t]==0){sums[k]=a[i]+sums[j];used[sums[k]]=1;k++;}

  }
 }
 sort(sums,sums+k);
 int ans=1;
 long long f=sums[0];
 //cout<<sums[0]<<endl;
 for(int i=1;i<k;i++)
 {
  //cout<<sums[i]<<endl;
  if(f!=sums[i]) {ans++;f=sums[i];}
 }
 //cout<<k<<endl;
 cout<<ans<<endl;
 return 0;
}
/*
5
1 -2 0 7 7


12


-2 -1 0 1 5 6 7 8 12 13 14 15
*/
