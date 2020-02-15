#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

vector<string> ukr(MAXN);


int main()
{
    ios_base::sync_with_stdio(false);
    int n, u;
    cin >> n >> u;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<u; i++)
            for(int j=0; j<u; j++)
                if(j>i)
                    ukr[i]=to_string(i)+" "+to_string(j)+" "+to_string(j)+" "+to_string(j)+" "+to_string(i);
    cout<<ukr[(n+1)/2];
    return 0;
}
