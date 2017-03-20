#include<iostream>
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int raz[500505];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n],i,j;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    cout<<(a[0]+a[n-1])%123456789012345<<"\n";
}
