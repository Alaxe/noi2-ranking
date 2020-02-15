#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define f first
#define s second
#define ll long long int
using namespace std;

const ll MAXN = 1e6;

ll N, U, n, a[MAXN], dp[64][64];
set<ll> uniq;
set<ll>::iterator sit;
vector<ll> tmp;

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> U;
    for(int i = 0; i < N; i ++){
        cin >> a[i];
        uniq.insert(a[i]);
    }
    for(int i = 1; i <= U; i ++){
        dp[1][i] = 1;
    }
    for(int pos = 2; pos <= uniq.size(); pos ++){
        for(int dig = 1; dig < U; dig ++){
            for(int prev = dig + 1; prev <= U; prev ++){
                dp[pos][dig] += dp[pos - 1][prev];
            }
        }
    }
    for(int dig = 1; dig <= U; dig ++){
        n += dp[uniq.size()][dig];
    }
    n = n / 2 + n % 2;
    int imaoshte = uniq.size();
    for(int pochva = 1; pochva <= U && imaoshte >= 0; pochva ++){
        if(n - dp[imaoshte][pochva] <= 0){
            tmp.pb(pochva);
            imaoshte --;
        }
        else{
            n -= dp[imaoshte][pochva];
        }
    }
    int idx = 0;
    bool ch[MAXN] = {0};
    for(sit = uniq.begin(); sit != uniq.end(); ++sit){
        for(int i = 0; i < N; i ++){
            if(a[i] == *sit && ch[i] == 0){
                a[i] = tmp[idx];
                ch[i] = 1;
            }
        }
        idx ++;
    }
    for(int i = 0; i < N; i ++){
        cout << a[i] << " ";
    } cout << endl;
}

