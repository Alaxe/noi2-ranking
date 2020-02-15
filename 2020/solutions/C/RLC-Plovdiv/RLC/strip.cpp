#include <iostream>
using namespace std;

long long complete(int seq[], int len, int lk, int rk)
{
    if (seq[0] == 1 && seq[len - 1] == 1) return 1;

    if (seq[lk - 1] == 0 && (rk + 1 >= len || seq[rk + 1] != 0)) {
        seq[lk-1] = 1;
        return complete(seq, len, lk-1, rk);
    }

    if (seq[rk + 1] == 0 && (lk - 1 < 0 || seq[lk - 1] != 0)) {
        seq[rk+1] = 1;
        return complete(seq, len, lk, rk+1);
    }

    if (seq[rk + 1] == 0 && seq[lk - 1] == 0) {
        int i, hseq1[len], hseq2[len];
        for (i = 0; i < len; i++) { hseq1[i] = seq[i]; hseq2[i] = seq[i]; };
        hseq1[lk-1] = 1; hseq2[rk+1] = 1;
        return complete(hseq1, len, lk-1, rk) + complete(hseq2, len, lk, rk+1);
    }

    return 0;
}

int main()
{
    int n, k; cin >> n >> k;
    int seq[n]; for (int i = 0; i < n; i++) seq[i] = 0;
    seq[k - 1] = 1;

    cout << complete(seq, n, k - 1, k - 1) << endl;
    return 0;
}

/*
for (int i = 0; i < len; i++) cout << seq[i] << " ";
    cout << "; lk: " << lk << "; rk:" << rk << endl;
    */
