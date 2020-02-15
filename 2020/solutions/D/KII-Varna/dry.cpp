#include<iostream>
using namespace std;
int h[100];
int main(){
int n,u,v,s=0,se=0,sd=0,ml=1000,md,i;
bool z=false;
cin>>n>>u>>v;
cin>>h[0];
for(i=1;i<n;i++)
{cin>>h[i];}
for(i=0;i<n;i++)
{if(h[i]>=h[i-1])s+=h[i-1];
else s+=h[i];
}
cout<<s*u*v<<endl;
}
