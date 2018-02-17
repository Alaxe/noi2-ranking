#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int k;
    cin>>n>>k;
    unsigned long long s = 1;
    for(int i=1;i<n;i++)
    {
        s*=10;
    }
    for(int i=s;;i++)
    {
        if(i%k==0){cout<<i<<endl;return 0;}
    }
    return 0;
}
