#include<iostream>
using namespace std;
int main() {
int n,m,br=0,cn=0,k=n;
cin>>n>>m;
while(n<=m)
{
    while(k)
    {
        cn=cn+k%10;
        k/=10;
    }
    n=n+cn;
    k=n;
    if(k<m)br++;
}
cout<<br;
}
