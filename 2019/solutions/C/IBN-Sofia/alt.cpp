#include <iostream>

using namespace std;

int k, m, n;
long long P[60][60];

long long V(int N, int A, int E) {
    if (A>N)
        return 0;
    if (N<0||A<0)
        return 0;
    if (P[N][A]!=-1)
        return P[N][A];
    if (N-2*A>=(E+k-1)/k)
        return 0;
    if (2*A-N>=(m-E+k-1)/k)
        return 0;
    P[N][A] = V(N-1, A, E) + V(N-1, A-1, E);
    return P[N][A];

}

int main() {
    cin >> k >> m >> n;
    unsigned long long sum = 0;
    for (int i = 1; i < m; ++i) {
        for (long long h = 0; h < 60; ++h) {
            for (long long g = 0; g < 60; g++){
                P[h][g] = -1;
            }
        }
        P[0][0]=1;
        for (long long j = 0 ; j < 60; ++j) {
            sum+=(unsigned long long)V(n-1, j, i);
        }
    }
    cout << sum << "\n ";
    return 0;
}
