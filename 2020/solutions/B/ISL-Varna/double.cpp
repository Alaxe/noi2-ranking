#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define ll long long int
using namespace std;

const ll MAXN = 256;

ll n, w1, w2, A[2*MAXN], ans;
set<ll> dp_sums[2*MAXN];
set<ll>::reverse_iterator rsit;
set<ll>::iterator sit;

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> w1 >> w2;
    for(ll i = 0; i < n; i ++){
        cin >> A[i];
    }
    sort(A, A + n);
    for(ll i = 0; i < n; i ++){ /// O(n^2), n = 200
        for(ll s = MAXN - 1; s > 0; s --){
            if(dp_sums[s].empty())
                continue;
            if(dp_sums[s + A[i]].empty() && s + A[i] <= 200)dp_sums[s + A[i]] = dp_sums[s], dp_sums[s + A[i]].insert(i);
        }
        if(dp_sums[A[i]].empty() && A[i] <= 200)dp_sums[A[i]].insert(i);
    }
    for(ll i = w1; i >= 0; i --){ /// ~ O(n ^ 3) n = 200
        if(!dp_sums[i].empty()){

            ll proh[MAXN] = {0}; for(sit = dp_sums[i].begin(); sit != dp_sums[i].end(); ++sit) proh[*sit] = 1;
            /// cout << "prohed: "; for(sit = dp_sums[i].begin(); sit != dp_sums[i].end(); ++sit) cout << *sit << " "; cout << endl;

            set<ll> lcl_dp[MAXN];
            for(ll j = 0; j < n; j ++){
                if(proh[j]) continue;
                for(ll s = MAXN - 1; s > 0; s --){
                    if(lcl_dp[s].empty())
                        continue;
                    if(lcl_dp[s + A[i]].empty() && s + A[i] <= 200)lcl_dp[s + A[j]] = lcl_dp[s], lcl_dp[s + A[j]].insert(j);
                }
                if(lcl_dp[A[j]].empty() && A[i] <= 200)lcl_dp[A[j]].insert(j);
            }
            ans = max(ans, i);
            for(ll j = w2; j >= 0; j --){
                if(!lcl_dp[j].empty()){
                    ans = max(ans, i + j);
                    break;
                }
            }
            break;
        }
    }
    for(ll i = w2; i >= 0; i --){ /// ~ O(n ^ 3) n = 200
        if(!dp_sums[i].empty()){

            ll proh[MAXN] = {0}; for(sit = dp_sums[i].begin(); sit != dp_sums[i].end(); ++sit) proh[*sit] = 1;
            /// cout << "prohed: "; for(sit = dp_sums[i].begin(); sit != dp_sums[i].end(); ++sit) cout << *sit << " "; cout << endl;

            set<ll> lcl_dp[MAXN];
            for(ll j = 0; j < n; j ++){
                if(proh[j]) continue;
                for(ll s = MAXN - 1; s > 0; s --){
                    if(lcl_dp[s].empty())
                        continue;
                    if(lcl_dp[s + A[j]].empty() && s + A[j] <= 200)lcl_dp[s + A[j]] = lcl_dp[s], lcl_dp[s + A[j]].insert(j);
                }
                if(lcl_dp[A[j]].empty() && A[i] <= 200)lcl_dp[A[j]].insert(j);
            }
            ans = max(ans, i);
            for(ll j = w1; j >= 0; j --){
                if(!lcl_dp[j].empty()){
                    ans = max(ans, i + j);
                    break;
                }
            }
            break;
        }
    }
    cout << ans << endl;
}
/**
1 1 1 1 1 1 1 1 1 1
2 3 10 4 5 12 67 80 92 45
*/
