#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,br=0;
    cin>>n;
    int a[n],b[n],comp;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        br=0;
        comp=a[i];
        for(int c=i;c<n;c++) if(comp<a[c]) br++;
        b[i]=br;
    }
    for(int i=0;i<n;i++)
    if(i==n-1) {cout<<b[i];}
    else {cout<<b[i]<<" ";}
    cout<<endl;
}
