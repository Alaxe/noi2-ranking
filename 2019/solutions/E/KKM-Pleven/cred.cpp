#include<iostream>
using namespace std;
int main(){
long long n,m,i,br=0,d;
cin>>n>>m;
for(i=n;i<=m;i++)
{
    d=i;
    br++;
    while(i>0)
    {
        d=d+i%10;
        i=i/10;
    }
    if(d<=m) br++;
}
cout<<br;
return 0;
}
