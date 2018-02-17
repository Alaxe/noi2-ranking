#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,q,maxi=0,ch,sum=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>ch;
        sum=sum+ch;
        if(ch>maxi)maxi=ch;
    }
    cin>>q;
    cout<<(maxi*n-sum)*q<<endl;
    return 0;
}
