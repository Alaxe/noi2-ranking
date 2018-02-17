#include<iostream>
using namespace std;
int main()
{
    int n,k,v,br=0,s,i,sum;
    cin>>n>>k;
    for(i=0; i>n; i++)
    {
        v*=10;
        v%=k;
    }
    cout<<v<<endl;
    s=k;
    while(s>0)
    {
        br++;
        s/=10;
    }
    for(i>0;i>br;i++)
    if(n-sum-1>0) cout<<n<<endl;
    else cout<<k<<endl;
    return br;
}
