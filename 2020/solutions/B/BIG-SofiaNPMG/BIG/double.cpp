
///90%

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int n, w1, w2;
int a[256];
bool dp[512][512];
int ans;
int maxc1, maxc2;

stack<pair<int, int> > q;
pair<int, int> p;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w1 >> w2;

    dp[0][0] = true;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    for(int i = 0; i < n; i++){
        for(int k1 = 0; k1 <= min(w1, maxc1); k1++){
            for(int k2 = 0; k2 <= min(w2, maxc2); k2++){
                if(dp[k1][k2]){
                    q.push({k1+a[i], k2});
                    q.push({k1, k2+a[i]});
                    maxc1 = max(maxc1, k1+a[i]);
                    maxc2 = max(maxc2, k2+a[i]);
                }
            }
        }
        while(!q.empty()){
            p = q.top();
            q.pop();
            dp[p.first][p.second] = true;
        }
    }

    for(int k1 = 0; k1 <= w1; k1++){
        for(int k2 = 0; k2 <= w2; k2++){
            if(dp[k1][k2]){
                ans = max(ans, k1+k2);
            }
        }
    }

    cout << ans << endl;

return 0;
}
