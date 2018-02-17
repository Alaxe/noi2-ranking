#include <iostream>
#include <vector>
using namespace std;

long long n, k, a, b;
const int MAXN = 101;
const int MAXK = 10001;
const unsigned long long INF = 10 + 1e18L;

vector<char> digits;

vector<string> generate(vector<string> prev) {
    vector<string> next;
    for (int i = 0; i < digits.size(); i++) {
        if (i%2 == 0) {
            for (int j = 0; j < prev.size(); j++) {
                next.push_back(digits[i] + prev[j]);
            }
        } else {
            for (int j = prev.size() - 1; j >= 0; j--) {
                next.push_back(digits[i] + prev[j]);
            }
        }
    }
    return next;
}

string max(string& x, string& y) {
    for(int i = 0; i < x.length(); i++) {
        if(x[i] < y[i]) return y;
        if(x[i] > y[i]) return x;
    }
    return x;
}

int sum(string &x) {
    int sum = 0;
    for(char c : x) sum += (c-'0');
    return sum;
}

int main() {
    cin >> n >> k >> a >> b;
    a--;b--;

    char d;
    for(int i = 0; i < n; i++) {
        cin >> d;
        digits.push_back(d);
    }

    vector<string> seq = {""};

    for(int i = 0; i < k; i++) {
        seq = generate(seq);
    }

    auto best = seq[a];
    int bestdiff = -1;
    for(long long i = a+1; i <= b; i++) {
        //cout << seq[i] << endl;
        best = max(best, seq[i]);
        int diff = sum(seq[i-1]) - sum(seq[i]);
        if(diff<0) diff *= -1;
        bestdiff = max(bestdiff, diff);
    }
    cout << best << " " << bestdiff << endl;
    return 0;
}

