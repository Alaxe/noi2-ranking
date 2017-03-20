#include <iostream>
#include <string>
using namespace std;

bool inc(short int digits[], int sz, int len, int n)
{
    digits[n]++;
    if (digits[n] == n + len - sz + 1) {
        if (n == 0) return false;
        if (!inc(digits, sz, len, n-1)) return false;
        digits[n] = digits[n-1] + 1;
    }
    return true;
}

bool inc(short int digits[], int sz, int len)
{
    return inc(digits, sz, len, sz-1);
}

void init(short int digits[], int sz)
{
    for (int i = 0; i < sz; i++)
        digits[i] = i;
}

int main()
{
    string str;
    int n;
    unsigned long long m;
    cin >> str >> n >> m;

    int num_count = 0;
    int len = str.size();
    for(int sz = 1; sz <= len; sz++) {
        short int digits[sz];
        init(digits, sz);
        do {
            unsigned long long num = 0;
            for (int i = 0; i < sz; i++) {
                num *= 10;
                num += str[digits[i]] - '0';
            }
            if(num % n == 0) ++num_count;
        } while (inc(digits, sz, len));
    }
    cout << num_count % m << endl;
    return 0;
}
