#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    if(k==1||k==n) cout<<"1"<<endl;
    else cout<<(k-1)*(n-k+1)<<endl;
    return 0;
}
