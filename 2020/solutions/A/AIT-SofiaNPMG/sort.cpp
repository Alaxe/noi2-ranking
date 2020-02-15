#include <bits/stdc++.h>
using namespace std;
int n, a [100005], idx [100005];
pair <int, int> b [100005];
int dp [1024][1024];
int main (){

    ios::sync_with_stdio (false);
    cin.tie (0);

    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> a [i];
        b [i].first = a [i];
        b [i].second = i;
    }
    sort (b, b + n);
    for (int i = 0; i < n; i ++) idx [b [i].second] = i;
    int br = 0;
    for (int i = 1; i < n; i ++) if (a [i] >= a [i - 1]) br ++;
    if (br == n - 1){
        cout << "0\n";
        return 0;
    }
    if (br == n - 2){
        for (int i = 1; i < n; i ++){
            if (a [i] < a [i - 1]){
                cout << a [i - 1] - a [i] << '\n';
                return 0;
            }
        }
    }
    for (int i = 0; i < idx [0]; i ++) dp [0][i] = a [0] - b [i].first;
    for (int i = 1; i < n; i ++){
        for (int j = 0; j < idx [i]; j ++){
            dp [i][j] = dp [i - 1][j] + a [i] - b [j].first;
        }
        for (int j = idx [i]; j < n; j ++){
            if (j == 0) dp [i][j] = dp [i - 1][j];
            else dp [i][j] = min (dp [i - 1][j] + b [j].first - a [i], dp [i][j - 1]);
        }
    }
    cout << dp [n - 1][n - 1] << '\n';
}
