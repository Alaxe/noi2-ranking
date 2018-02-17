#include <iostream>

using namespace std;

int main() {

    int n, q;
    cin >> n;
    int fHeight[n] = {};

    for (int i = 0; i < n; i++) {
        cin >> fHeight[i];
    }

    cin >> q;

    int highestFlower = -9999;
    // Max
    for (int i = 0; i < n; i++) {
        int current = fHeight[i];
        highestFlower = max(highestFlower, current);
    }
    int total = 0;

    for (int i = 0; i < n; i++) {
        int current = fHeight[i];
        total += highestFlower - current;
    }

    cout << total * q << endl;
}

