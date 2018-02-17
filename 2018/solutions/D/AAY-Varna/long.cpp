#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,s=1,i,p,br=0;
    cin>>n>>k;
    for(i=0; i<n-1; i++)
    {
        s*=10;
        s%=k;
    }
    p=k;
    while(p>0)
    {
        br++;
        p/=10;
    }
    if(n-br-1>=0)
    {
        cout<<1;
        for(i=0; i<n-br-1; i++)
        {
            cout<<0;
        }
        if(s!=0)cout<<k-s<<endl;
        else
        {
            for(i=0; i<br; i++)
            {
                cout<<0;
            }
            cout<<endl;
        }
    }
    else cout<<k<<endl;

}
