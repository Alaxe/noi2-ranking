#include<iostream>
using namespace std;
int n,m,br,d,k;
int main()
{
    cin>>n>>m;
    k=n%10;
    d=n+n/10+k;
    if(d<m) br++;
    cout<<br<<endl;;
return 0;
}
