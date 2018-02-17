#include<iostream>
using namespace std;
int x[100000],pot[100000],ans[11];
int main()
{
 int t;
 int n,max1=0,to=0;

 cin>>t;
 for(int i=0;i<t;i++)
 {
  cin>>n;
  for(int j=0;j<n;j++)
  {
   cin>>x[j];
   if(to<x[j]) to=x[j];
   if(to<j+1) to=j+1;
   pot[x[j]]++;
   pot[j+1]++;
   //if(max1<pot[x[j]]) max1=pot[x[j]];
   //if(max1<pot[j+1]) max1=pot[j+1];
  }

  for(int l=0;l<=to;l++){if(max1<pot[l])max1=pot[l];pot[l]=0;}

  to=0;
  ans[i]=max1;
  max1=0;
 }
 for(int i=0;i<t;i++) cout<<ans[i]<<endl;
 return 0;
}
/*
2
4
4 1 2 3
5
4 1 2 3 4
*/
