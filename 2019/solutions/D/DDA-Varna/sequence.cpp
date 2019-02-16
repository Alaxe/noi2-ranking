#include<bits/stdc++.h>
using namespace std;
unsigned long long n,k,d,brc;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    if(k%2==1)
    {
        d=(k-1)/2;
        brc=((1+n+d)*(n+d))-(n+d);
        brc=brc-(n-1);
        cout<<brc<<endl;
    }
    if(k%2==0)
    {
        d=(k-2)/2;
        brc=((1+n+d)*(n+d))-(n+d);
        brc+=n;
        cout<<brc<<endl;
    }
}
