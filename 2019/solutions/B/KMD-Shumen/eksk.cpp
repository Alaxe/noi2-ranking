#include<iostream>
using namespace std;
int n,u[1024],v[1024];
void read()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>u[i]>>v[i];
    }
    if(n==1)cout<<1<<endl;
    if(n%3==0)cout<<n/3;
    else cout<<n/2;
}
int main()
{
    read();

    return 0;
}
