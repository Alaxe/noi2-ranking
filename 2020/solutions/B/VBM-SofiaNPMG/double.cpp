#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 210;

int arr[MAX_N];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, w1, w2;
    int Max = 0, answer = 0;

    cin >> n >> w1 >> w2;
    if (w1 > w2) {
        swap(w1, w2);
    }
    int sum = w1 + w2;
    for (int i = 0; i < n; ++ i) {
        cin >> arr[i];
    }

    int depth = 0;
    bool used[201];
    sort(arr + 0, arr + n);

    while (depth <= 5000) {
        if (answer == sum) {
            cout << sum << '\n';
            return 0;
        }
        Max = 0;
        fill_n(used + 0, n, false);
        int curr = 0;
        for (int i = n - 1; i >= 0; -- i) {
            if (curr + arr[i] <= w1) {
                curr += arr[i];
                used[i] = true;
            }
        }
        Max += curr;
        curr = 0;
        for (int i = 0; i < n; ++ i) {
            if (used[i]) {
                continue;
            }
            if (curr + arr[i] <= w2) {
                curr += arr[i];
            }
        }
        Max += curr;
        answer = max(Max, answer);
        ++ depth;
        random_shuffle(arr + 0, arr + n);
    }
    cout << answer << '\n';
    return 0;
}
