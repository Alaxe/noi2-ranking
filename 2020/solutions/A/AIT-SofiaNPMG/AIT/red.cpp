#include <bits/stdc++.h>
using namespace std;
int n, m, k, w;
int a [100005], b [100005];
long long br [2000006][2];
void solve2 (){
    int lastdif = 0;
    for (int i = 1; i < n; i ++){
        if (a [i] != a [i - 1]) lastdif = i;
        if (i - lastdif + 1 >= k) br [a [i]][0] ++;
    }
    lastdif = 0;
    for (int i = 1; i < m; i ++){
        if (b [i] != b [i - 1]) lastdif = i;
        if (i - lastdif + 1 >= k) br [b [i]][1] ++;
    }
    long long ans = 0;
    for (int i = 0; i <= 2000000; i ++){
        ans += br [i][0] * br [i][1];
    }
    cout << ans << '\n';
}
vector <vector <int> > seq1, seq2;
void solve1 (){
    int lastdif = 0;
    for (int i = 1; i <= n; i ++){
        if (a [i] <= a [i - 1]){
            if (i - lastdif >= k){
                vector <int> v;
                for (int j = lastdif; j < i; j ++) v.push_back (a [j]);
                seq1.push_back (v);
            }
            lastdif = i;
        }
    }
    lastdif = 0;
    for (int i = 1; i <= m; i ++){
        if (b [i] <= b [i - 1]){
            if (i - lastdif >= k){
                vector <int> v;
                for (int j = lastdif; j < i; j ++) v.push_back (b [j]);
                seq2.push_back (v);
            }
            lastdif = i;
        }
    }
    long long ans = 0;
    for (auto v1 : seq1){
        int sz1 = v1.size ();
        for (auto v2 : seq2){
            int sz2 = v2.size (), br = 0;
            int i = 0, j = 0;
            while (i < sz1 && j < sz2){
                if (v1 [i] == v2 [j]){
                    br ++, i ++, j ++;
                    if (br >= k) ans ++;
                }
                else if (v1 [i] < v2 [j]) br = 0, i ++;
                else br = 0, j ++;
            }
        }
    }
    cout << ans << '\n';
}
void solve1_smallk (){
    int lastdif = 0;
    for (int i = 1; i < n; i ++){
        if (a [i] <= a [i - 1]){
            lastdif = i;
        }
        else if (i - lastdif + 1 >= k){
            vector <int> v;
            for (int j = i - k + 1; j <= i; j ++) v.push_back (a [j]);
            seq1.push_back (v);
        }
    }
    lastdif = 0;
    for (int i = 1; i < m; i ++){
        if (b [i] <= b [i - 1]){
            lastdif = i;
        }
        else if (i - lastdif + 1 >= k){
            vector <int> v;
            for (int j = i - k + 1; j <= i; j ++) v.push_back (b [j]);
            seq2.push_back (v);
        }
    }
    sort (seq1.begin (), seq1.end ());
    sort (seq2.begin (), seq2.end ());
    vector <pair <vector <int>, long long> > S1, S2;
    if (seq1.empty () || seq2.empty ()){
        cout << "0\n";
        return;
    }
    S1.push_back ({seq1 [0], 1});
    int sz1 = seq1.size ();
    for (int i = 1; i < sz1; i ++){
        if (seq1 [i] == seq1 [i - 1]) S1.back ().second ++;
        else S1.push_back ({seq1 [i], 1});
    }
    S2.push_back ({seq2 [0], 1});
    int sz2 = seq2.size ();
    for (int i = 1; i < sz2; i ++){
        if (seq2 [i] == seq2 [i - 1]) S2.back ().second ++;
        else S2.push_back ({seq2 [i], 1});
    }
    sz1 = S1.size ();
    sz2 = S2.size ();
    int i = 0, j = 0;
    long long ans = 0;
    while (i < sz1 && j < sz2){
        if (S1 [i].first == S2 [j].first) ans += S1 [i].second * S2 [j].second, i ++, j ++;
        else if (S1 [i].first < S2 [j].first) i ++;
        else j ++;
    }
    cout << ans << '\n';
}
int main (){

    ios::sync_with_stdio (false);
    cin.tie (0);

    cin >> w >> k;
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a [i];
    cin >> m;
    for (int i = 0; i < m; i ++) cin >> b [i];
    if (w == 2) solve2 ();
    else if (k <= 25) solve1_smallk ();
    else solve1 ();

}
