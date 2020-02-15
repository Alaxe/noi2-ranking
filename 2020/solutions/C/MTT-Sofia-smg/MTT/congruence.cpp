#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
char a[30], b[30];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, s2, mini="", maxi="";
    long long siz;
    char minl='A', maxl='Z';
    cin >> s;
    siz=s.size();
    s2=s;
    sort(s2.begin(), s2.end());
    for (int i=0; i<siz; i++)
    {
        a[s2[i]-'A'+1]=minl; minl++;
        while (i<siz-1 && s2[i]==s2[i+1])i++;
    }
    reverse(s2.begin(), s2.end());
    for (int i=0; i<siz; i++)
    {
        b[s2[i]-'A'+1]=maxl; maxl--;
        while (i<siz-1 && s2[i]==s2[i+1])i++;
    }
    for (int i=0; i<siz; i++)
    {
        mini=mini+a[s[i]-'A'+1];
        maxi=maxi+b[s[i]-'A'+1];
    }
    cout << mini << endl;
    cout << maxi << endl;
    return 0;
}
