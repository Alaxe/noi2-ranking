#include <bits/stdc++.h>
using namespace std;
int n, a [100005];
int t [400025];
void upd (int l, int r, int pos, int x, int val){
    if (l == r){
        t [pos] = max (t [pos], val);
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid){
        upd (l, mid, pos << 1, x , val);
    }
    else{
        upd (mid + 1, r, (pos << 1) + 1, x, val);
    }
    t [pos] = max (t [pos << 1], t [(pos << 1) + 1]);
}
int query (int l, int r, int pos, int ql, int qr){
    if (l >= ql && r <= qr) return t [pos];
    if (l > qr || r < ql) return 0;
    int mid = (l + r) >> 1;
    return max (query (l, mid, pos << 1, ql, qr), query (mid + 1, r, (pos << 1) + 1, ql, qr));
}
int ans1 [100005], ans2 [100005];
int main (){

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a [i];
        if (a [i] == 1) ans1 [i] = 1;
        else ans1 [i] = query (1, 100001, 1, 1, a [i] - 1) + 1;
        upd (1, 100001, 1, a [i], ans1 [i]);
    }
    for (int i = 1; i < 400010; i ++){
        t [i] = 0;
    }
    for (int i = n; i > 0; i --){
        if (a [i] == 1) ans2 [i] = 1;
        else ans2 [i] = query (1, 100001, 1, 1, a [i] - 1) + 1;
        upd (1, 100001, 1, a [i], ans2 [i]);
    }
    int maxi = 0;
    for (int i = 1; i <= n; i ++){
        maxi = max (maxi, ans1 [i] + ans2 [i] - 1);
    }
    cout << maxi << '\n';

    return 0;
}
