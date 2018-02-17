#include <iostream>
using namespace std;

int main()
{
    unsigned long long int M, N;
    cin >> M >> N;
    unsigned long long d = 0;
    unsigned int i = 0;
    while (d < M) {
        i++;
        d += i;
        d += i;
    }
    unsigned int ans = i;
    while (d <= N) {
        i++;
        d += i;
        d += i;
    }
    cout << i - ans << endl;
    return 0;
}
