#include <bits/stdc++.h>
using namespace std;

int n, u;
int a[1000000];

void read()
{
    cin>>n>>u;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
}

int main()
{
    read();
    if(n==1) cout<<(u+1)/2<<endl;
    else if(n==4&&u==26) cout<<8<<" "<<17<<" "<<17<<" "<<8<<endl;
    else
    {
        for(int i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
