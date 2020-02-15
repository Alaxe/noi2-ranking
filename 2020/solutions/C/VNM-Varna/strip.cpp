#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, k;
long long pasc[60]={1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int ch1=k-1, sum=n-1;
    for(int i=1; i<=sum; i++)
    {
        for(int j=i; j>0; j--) pasc[j]+=pasc[j-1];
    }
    cout<<pasc[ch1]<<endl;
    return 0;
}
