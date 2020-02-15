#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
bool b[32];
char newc1[32];
char newc2[32];
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    int sz=s.size();
    for(int i=0;i<sz;++i)
    {
        b[s[i]-'A']=1;
    }
    char c='A';
    for(int i=0;i<26;++i)
    {
        if(b[i])
        {
            newc1[i]=c;
            c++;
        }
    }
    c='Z';
    for(int i=25;i>=0;--i)
    {
        if(b[i])
        {
            newc2[i]=c;
            c--;
        }
    }
    for(int i=0;i<sz;++i)
    {
        cout<<newc1[s[i]-'A'];
    }
    cout<<"\n";
    for(int i=0;i<sz;++i)
    {
        cout<<newc2[s[i]-'A'];
    }
    cout<<"\n";
return 0;
}
