#include <iostream>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int FIRST, MUL, ADD, MOD;
    cin >> FIRST >> MUL >> ADD >> MOD;
    unsigned long long rating = FIRST;
    unsigned long long best = FIRST;
    unsigned long long current = FIRST;
    /// If day == best_expires_in; then it has expired
    int best_expires_in = K;

    unsigned long long *arr = new unsigned long long[K];
    int arr_len = 1;
    int arr_index = 0;
    arr[arr_index++] = current;
    arr_index %= K;

    for (int day = 1; day < N; day++) {
        current *= MUL;
        current += ADD;
        current %= MOD;

        int cur_index = arr_index;
        arr[arr_index++] = current;
        arr_index %= K;
        arr_len++;

        if (current > best) {
            best = current;
            best_expires_in = day + K;
        }

        if (best_expires_in == day) {
            int best_i = cur_index;
            best = current;
            for (int i = 0; i < K; i++) {
                if (arr[i] > best) {
                    best = arr[i];
                    best_i = i;
                }
            }

            int diff;
            if (best_i <= cur_index) {
                diff = cur_index - best_i;
            } else {
                diff = cur_index + K - best_i;
            }
            best_expires_in = day - diff + K;
        }

        rating += best;
    }
    cout << rating << endl;
    return 0;
}
