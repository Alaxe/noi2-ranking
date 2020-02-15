#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string v;
    cin >> v;
    int n = v.size();
    int relations[n];
    pair<int, int> sorted[n];
    for (int i = 0; i < n; i++) {
        sorted[i].first = v[i];
        sorted[i].second = i;
    }
    sort(sorted, sorted + n);
    int currStep = 0, currValue = sorted[0].first;
    for (int i = 0; i < n; i++) {
        if (sorted[i].first == currValue) {
            sorted[i].first = currStep;
        } else {
            currValue = sorted[i].first;
            currStep++;
            sorted[i].first = currStep;
        }
        relations[sorted[i].second] = sorted[i].first;
    }
    for (int i = 0; i < n; i++) {
        char tool = relations[i] + 'A';
        cout << tool;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        char tool = relations[i] + 'A' + (26 - currStep - 1);
        cout << tool;
    }
    return 0;
}
