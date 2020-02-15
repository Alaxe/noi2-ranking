#include <bits/stdc++.h>
using namespace std;
string s, s1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for(int i=0; i<s.size(); i++)
        if(s[i]!='('&&s[i]!=')')
        s1+=s[i];
    cout<<s1<<endl;
    return 0;
}
