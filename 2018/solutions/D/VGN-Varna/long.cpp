#include<iostream>
using namespace std;
int main()
{
    long long n,k,p=1,i,m,j;
    cin>>n>>k;
    for(i=1;i<n;i++)
    {
    p=p*10;
    }

    if(p%k==0)cout<<p;
    else cout<<((p/k)+1)*k<<endl;



}
