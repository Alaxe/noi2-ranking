#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[130];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int br = 0, siz;
    char zn = 'a';
    string s;
    cin >> s;
    if( s.size()%2 == 0 )siz = s.size()/2;
    else siz = s.size()/2+1;
    for( int i = 0; i < s.size(); i++)
    {
        a[(int)s[i]]++;
    }
    for( int i = 1; i < s.size(); i++)
    {
        if( s[i] == s[i-1] )
            br++;
        if( br == 2 )
        {
            if( s[i] != zn)
            {
                s[i] = zn;
                if( a[(int)zn] >= siz) zn = (char)(int)zn+1;
                a[(int)zn]++;
            }
            else
            {
                s[i] = (char)(int)zn+1;
                if( a[(int)zn+1] >= siz) zn = (char)(int)zn+2;
                a[(int)zn+1]++;

            }
            br = 0;
        }

    }
    cout << s << endl;
    return 0;
}
