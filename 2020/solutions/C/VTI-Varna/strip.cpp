#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n,k,i,j,otg=1,x,y;
    cin>>n>>k;
    x=k-1;
    y=n-k;
    if(x>y)swap(x,y);
    for(i=y+1;i<n;i++)
    {
        otg=otg*i;
    }
    for(j=1;j<=x;j++)
    {
        otg/=j;
    }
    cout<<otg<<endl;
}
