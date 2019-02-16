#include<iostream>
using namespace std;
int main(){
long long a,b,br1=0,br2=0,i,j;
cin>>a>>b;
for(i=a;i<=b;i++)
{
    for(j=1;j<=i;j++)
    {
        if(i%j==0) br1++;
    }
    if(br1%2==1) br2++;
    br1=0;
}
cout<<br2;
return 0;
}
