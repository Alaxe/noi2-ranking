#include <bits/stdc++.h>
#define REP(a,b)for(int i=(a); i<(b); i++)
#define REP2(a,b)for(int j=(a); j<(b); j++)
#define REP3(a,b)for(int k=(a); k<(b); k++)
#define all(x) x.begin(),x.end()
#define SZ(x) x.size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
int mod = 1000000007;
string s;
int mem[100][100][101];
vector<int> V[101];
int rec(int l, int r, int len) {
    int ans = 0;
    if(mem[l][r][len])return mem[l][r][len];
    if(len==0)return 1;
    if(len==1) {
        //cout << "len 1: " << l << " " << r << ": " << s[l] << " " << s[r] << endl;
        return (r-l+1);
    }
    for(int i = l; i <= r-len+1; ++i) {
        for(int j = r; j >= l+len-1; --j) {
            if(j-i+1 < len)break;
            if(s[i]!=s[j])continue;
            int res = rec(i+1,j-1,len-2);
            //cout << i << " " << j << " " << res << endl;
            //cout << s[i] << " " << s[j] << endl;
            ans+=res;
            ans%=mod;
        }
    }
    return mem[l][r][len] = ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int ans2 = 0;
    REP(1,s.size()+1)ans2+=rec(0,s.size()-1, i), ans2%=mod;
    cout << ans2 << endl;
}
