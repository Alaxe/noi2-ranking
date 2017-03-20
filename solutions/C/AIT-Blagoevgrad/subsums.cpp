#include <bits/stdc++.h>
using namespace std;
int n, a [1000], x [1000][1000];
int main(){

    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
	cin >> n;
	for (int i = 0; i < n; i ++){
        cin >> a [i];
        x [i][i] = 1;
	}
	sort (a, a + n);
	for (int i = 1; i < n; i ++){
        if (a [i - 1] == 0 && a [i] == 0) x [i - 1][i] = 1;
        else if (a [i - 1] == 0 || a [i] == 0) x [i - 1][i] = 2;
        else if (a [i - 1] == a [i]) x [i - 1][i] = 2;
        else x [i - 1][i] = 3;
	}
	for (int k = 2; k < n; k ++){
        int nk = n - k;
        for (int i = 0; i < nk; i ++){
            int l = a [i], r = a [i + k];
            if (l == 0){
                if (a [i + 1] != 0) x [i][i + k] = x [i + 1][i + k] + 1;
                else x [i][i + k] = x [i + 1][i + k];
            }
            else if (r == 0){
                if (a [i + k - 1] != 0) x [i][i + k] = x [i][i + k - 1] + 1;
                else x [i][i + k] = x [i][i + k - 1];
            }
            else{
                if (l == r){
                    x [i][i + k] = k + 1;
                }
                else{
                    int indl = upper_bound (a, a + n, l) - a;
                    int indr = lower_bound (a, a + n, r) - a - 1;
                    int indx;
                    if (indl > indr){
                        x [i][i + k] = x [i][i + k - 1] + x [i + 1][i + k] - x [i + 1][i + k - 1] + 1;
                    }
                    else{
                    x [i][i + k] = x [i][i + k - 1] + x [i + 1][i + k] - x [i + 1][i + k - 1] + x [indl][indr] + 1;
                    if (binary_search (a + i, a + i + k, 0)) x [i][i + k] --;}
                }
            }
        }
	}
	cout << x [0][n - 1] << '\n';

	return 0;
}
