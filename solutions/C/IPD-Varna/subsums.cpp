#include <iostream>
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int t, vsize, el, br;
vector <int> v;
int main ()
{
    cin>>t;
    for (int ti=0; ti<t; ti++)
    {
        cin>>el;
        vsize=v.size();
        v.push_back (el);
        for (int i=0; i<vsize; i++)
        {
            v.push_back (el+v[i]);
            ///cout<< el+v[i]<<endl;
        }
    }

    vsize=v.size();
    sort(v.begin(), v.end());
    for (int i=1; i<=vsize; i++) if (v[i-1]!=v[i]) br++;
    cout<<br<<endl;
}
/*
5
1 -2 0 7 7


12
*/
