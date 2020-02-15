#include <iostream>
using namespace std;
int main (){
long long x,n;
cin>>n>>x;
for(long long i=1;i<=n;i++)
{
    if(i%2==0)
    {
        x=1;
    }
    if(i%2!=0)
    {
        x=0;
    }
}
cout<<x;
}
