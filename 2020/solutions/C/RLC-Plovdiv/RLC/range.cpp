#include <iostream>

using namespace std;

int main()
{
    int i, j, n; cin >> n; int seq[n];
    for (i = 0; i < n; i++) cin >> seq[i];
    int rn; cin >> rn; int req[rn][3];

    for (i = 0; i < rn; i++) {
        cin >> req[i][0] >> req[i][1];
        req[i][2] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < rn; j++) {
            if (seq[i] >= req[j][0] && seq[i] <= req[j][1]) req[j][2] += 1;
        }
    }

    for (j = 0; j < rn; j++) cout << req[j][2] << endl;
    return 0;
}
