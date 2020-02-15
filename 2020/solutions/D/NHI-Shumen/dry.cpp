#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int u;
cin>>u;
int v;
cin>>v;
int a[105];
for(int i=1;i<=n;i++){cin>>a[i];}
int i=1,j=0;
int water=0,ans=0;
while(i<=n-1)
{
    j=i+1;
    int max=a[j];
    int maxind=j;
    while(a[i]>a[j]&&j<=n-1)
    {
        j++;
        if(a[j]>max){max=a[j];maxind=j;}
    }
    if(j==i+1)water=v*((j-i)*u)*a[i];
    else water=v*((j-i)*u)*max;
    ans=ans+water;
    i=maxind;
}
cout<<ans<<endl;
/*
5 1 1
2 4 8 5 7
*/
return 0;
}
