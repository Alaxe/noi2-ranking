#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

string s;
char zam[300], zam2[300];
bool used[300];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>s;
    int n=s.size();
    for(int i=0; i<n; i++) used[s[i]]=1;
    char tek='A';
    for(int i=0; i<256; i++)
    {
        if(used[i])
        {
            zam[i]=tek;
            tek++;
        }
    }
    tek='Z';
    for(int i=255; i>=0; i--)
    {
        if(used[i])
        {
            zam2[i]=tek;
            tek--;
        }
    }
    string res1;
    res1.resize(n);
    for(int i=0; i<n; i++) res1[i]=zam[s[i]];
    cout<<res1<<endl;
    for(int i=0; i<n; i++) s[i]=zam2[s[i]];
    cout<<s<<endl;
    return 0;
}
