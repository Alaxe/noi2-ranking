#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6+10;


short int arr[MAX_N];
int n, u;

bool cmp(pair<int, int> lhs, pair<int, int> rhs) {
    return lhs.second < rhs.second;
}

void get_base() {
    vector<pair<int, int> > base;
    for (int i = 0; i < n; ++ i) {
        base.push_back(make_pair(arr[i], i));
    }
    sort(base.begin(), base.end());
    sort(arr + 0, arr + n);
    int curr = 1;
    for (int i = 0; i < n; ++ i) {
        for (int j = i + 1; j < n; ++ j) {
            if (base[i].first != base[j].first) {
                for (int k = i; k < j; ++ k) {
                    base[k].first = curr;
                }
                i = j - 1;
                ++ curr;
                break;
            } else if (j == n - 1) {
                for (int k = i; k < n; ++ k) {
                    base[k].first = curr;
                }
                ++ curr;
            }
        }
    }
    if (arr[n - 1] == arr[n - 2]) {
        base[n - 1].first = curr - 1;
    } else {
        base[n - 1].first = curr;
    }
    sort(base.begin(), base.end(), cmp);
    for (int i = 0; i < n; ++ i) {
        arr[i] = base[i].first;
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> u;
    for (int i = 0; i < n; ++ i) {
        cin >> arr[i];
    }
    get_base();
}
