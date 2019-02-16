#include<iostream>
using namespace std;
int main(){
long long i,j,k,n,num;
cin>>n;
for(i=1;i<=k;i++)
{
    for(j=1;j<=n;j++)
    {
       if(n==1) num=1;
       if(n++) num=num+2;
    }
}
cout<<num;
return 0;
}
