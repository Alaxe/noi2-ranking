#include<bits/stdc++.h>
using namespace std;
int red[100003];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,a[100003],b[100003];
    int i,j,k,i2;
    int br[100003];
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>red[i];
    }
    cin>>m;
    for(j=0; j<m; j++)
    {
        cin>>a[j]>>b[j];
    }
    for(j=0; j<m; j++)
    {
        int k;
        while (k<m)
            if(a[j]<=red[i]<=b[j]) br[k]++;
        k++;
    }
    int maxi=red[0],mini=red[0];
    if(maxi<red[i]) maxi=red[i];
    else if(maxi<a[j]) cout<<"0"<<endl;
    else if(mini>red[i]) mini=red[i];
    else if(mini>b[j]) cout<<"0"<<endl;
    for(int k=0; k<m; k++)
    {
        cout<<br[k]<<endl;
    }
    return 0;
}
/*
6
9 1 3 10 3 4
3
1 4
9 12
15 20
*/

