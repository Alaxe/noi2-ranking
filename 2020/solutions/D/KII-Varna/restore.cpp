#include<iostream>
using namespace std;
int a[100000];
int b[100000];
int main(){
int n,i,j;
cin>>n;
for(i=0;i<n;i++)
{cin>>a[i];}
for(i=0;i<n;i++)
{for(j=i+1;j<n;j++)
{if(a[i]<a[j])b[i]++;}
cout<<b[i]<<" ";}
cout<<endl;}
