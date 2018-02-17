#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double m, n;

double eps = 0.000001;

void solve() {

    scanf("%lf%lf", &m, &n);

    double F, S;

    m/= 2.00;
    n/= 2.00;

    F = (sqrt(1+8.00*m) - 1) / 2.00;

    if(F - floor(F) < eps) F -= 1.00;
    else F = floor(F);

    S = (sqrt(1+8.00*n) - 1) / 2.00;

    S = floor(S);

    printf("%.0lf\n", S-F);
}

int main() {

    solve();
    return 0;
}
