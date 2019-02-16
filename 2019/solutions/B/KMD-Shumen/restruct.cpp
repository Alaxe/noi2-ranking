#include<iostream>
using namespace std;
int n,bill,a[1024],n1,maxn=0;
void read()
{
    cin>>n>>bill;
    for(int i=1;i<=n;i++)
    {
        cin>>n1;
        for(int j=1;j<=n1;j++)
        {
            cin>>a[j];
            if(a[j]>maxn)maxn=a[j];
        }
    }
}
int main()
{
    read();
    cout<<(n*bill)*2+(maxn-n)*(bill*2);

    return 0;
}

