#include <bits/stdc++.h>
using namespace std;
int t, n, x, v [100002];
int main(){

    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cin >> t;
    for (int j = 0; j < t; j ++){
        cin >> n;
        if (n == 3){
            cin >> x; cin >> x; cin >> x;
            cout << "3\n";
            continue;
        }
        for (int i = 0; i < n; i ++){
            cin >> x;
            v [x] ++;
        }
        int maxi = 0;
        for (int i = 1; i <= n; i ++){
            maxi = max (maxi, v [i]);
            v [i] = 0;
        }
        cout << maxi + 1 << '\n';
    }

	return 0;
}
