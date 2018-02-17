#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    unsigned long long A, B;

    unsigned long long M, N;
    cin >> M >> N;

    A = sqrt(M);
    B = A+1;

    unsigned long long nTotalCount = 0;

    while (true)
    {
        if (A*B <= N && A*B >= M)
            nTotalCount++;

        if (A*B > N)
            break;

        A++;
        B++;
    }

    cout << nTotalCount;

    return 420;
}
