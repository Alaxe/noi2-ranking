#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, u, num[100000];
    cin>>n>>u;
    for(int i=0; i<n; i++) cin>>num[i];
    for(int j=0; j<n; j++) cout<<(num[j]+u)/2<<endl;

    return 0;
}

