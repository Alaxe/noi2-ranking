#include<iostream>
using namespace std;
int main()
{
    int n,k,nach,prib;
    cin>>n>>k;
    nach=n*(n-1)+1;
    prib=n+n-1;
    if(k==1){cout<<nach<<endl;return 0;}
    if(k==2){cout<<nach+prib<<endl;return 0;}
    if((k-1)%4!=0)cout<<nach+k/2*prib+((k-1)/4)*(2*((k/2)+k%2))+k/2+k%2<<endl;
    else cout<<nach+k/2*prib+((k-1)/4)*(2*((k/2)+k%2))<<endl;
}
