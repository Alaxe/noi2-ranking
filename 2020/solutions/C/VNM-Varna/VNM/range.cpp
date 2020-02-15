#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int n;
int a[100800];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int p;
        cin>>p;
        a[p]++;
    }
    for(int i=1; i<=100200; i++) a[i]+=a[i-1];
    int m;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int t1, t2;
        cin>>t1>>t2;
        cout<<a[t2]-a[t1-1]<<endl;
    }
    return 0;
}
