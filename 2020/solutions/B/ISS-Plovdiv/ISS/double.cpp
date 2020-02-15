#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long n, w1, w2, w3, w, br=0;
    cin>>n>>w1>>w2;
    long long m[n];
    for (int i=0; i<n; i++)
    {
        cin>>m[i];
    }
    sort (m, m+n);
    w=w1;
    w3=w1;
    if (w<w2)w=w2;
    if (w3>w2)w3=w2;
    for (int i=n-1; i>=0; i--)
    {

            if(w>=m[i])
            {
                br=br+m[i];
                w=w-m[i];
            }
            else
            {
                 if(w3>=m[i])
                br=br+m[i];
                w3=w3-m[i];
            }
    }
cout<<br<<endl;
    return 0;
}
