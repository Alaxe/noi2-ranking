#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int h[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, u, v, V=0, i, i1, j, Max;
    cin >> n >> u >> v;
    for(i=0; i<n; i++) cin >> h[i];
    i=0;
    while(i<n)
    {
        while(h[i]<h[i+1]) V+=u*v*h[i++];

        if(h[i]>h[i+1])
        {
            Max=0;
            i1=i+1;
            j=i+1;
            while(h[i]>h[j] && j<n)
            {
                if(h[j]>Max){Max=h[j]; i1=j;}
                j++;
            }
            V+=Max*(i1-i)*u*v;
            i=i1;
        }
    }
    cout << V << endl;
    return 0;
}
