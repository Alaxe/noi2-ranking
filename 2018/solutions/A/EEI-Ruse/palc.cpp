#include<iostream>
#include<vector>
using namespace std;
const int MAX_N=128;
const long long MOD=(1e9)+7;
long long pals[MAX_N][MAX_N]; //palindromes in the interval from i to j
string s;
int n;
long long ans;
void solve()
{
    n=s.size();
    for (int i=0;i<n;++i)
    {
        pals[i][i]=1;
    }
    for (int d=1;d<n;++d)
    {
        for (int i=0;i<n-d;++i)
        {
            int j=i+d;
            pals[i][j]=MOD+pals[i][j-1]+pals[i+1][j]-pals[i+1][j-1];
            if (s[i]==s[j]) pals[i][j]+=pals[i+1][j-1]+1;
            pals[i][j]%=MOD;
        }
    }
    ans=pals[0][n-1];
}
void input()
{
    cin>>s;
}
void output()
{
    cout<<ans<<endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    output();
    return 0;
}
