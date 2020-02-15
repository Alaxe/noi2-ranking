#include <iostream>
using namespace std;
int main () {
    long long steni, raz, shir, sum = 0, obem = 0;
    cin >> steni >> raz >> shir;
    long long vis[steni];
    for (int i = 0; i < steni; i++) {
        cin >> vis[i];
    }
    for (long long k = 0; k < steni; k++) {
        if (vis[k] <= vis[k + 1]) {
            obem = raz * shir * vis[k];
            sum = sum + obem;
            obem = 0;
        } else {
            for (long long  g = 2; g < steni - k; g++) {
                if (vis[k + 1] <= vis[k + g] and vis[k] > vis[k + 1]) {
                    if (vis[k] > vis[k + g]) {
                        obem = (g * raz) * shir * vis[k + g];
                    }
                    if (vis[k + g] > vis[k] or vis[k + g] == vis[k]) {
                        obem = (g * raz) * shir * vis[k];
                    }
                    k = k + g;
                }
            }
            sum = sum + obem;
            obem = 0;
        }
    }
    cout << sum <<endl;

    return 0;
}
