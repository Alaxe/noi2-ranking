#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> generate(vector<string> prev, vector<char> digits) {
    vector<string> next;
    for (int i = 0; i < digits.size(); i++) {
        if (i % 2 == 0) {
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

int char_to_int(char d) {
    return d - '0';
}

long long int str_to_int(string num) {
    long long res = 0;
    for (int i = 0; i < num.size(); i++) {
        res = res*10 + char_to_int(num[i]);
    }
    return res;
}

long long int max(vector<string> nums) {
    long long int max = 0;
    long long int curr;
    for (int i = 0; i < nums.size(); i++) {
        curr = str_to_int(nums[i]);
        if (curr > max) {
            max = curr;
        }
    }
    return max;
}

vector<long long int> sum_digits(vector<string> nums) {
    vector<long long int> res;
    long long int curr;
    for (int i = 0; i < nums.size(); i++) {
        curr = 0;
        for (int j = 0; j < nums[i].size(); j++) {
            curr += char_to_int(nums[i][j]);
        }
        res.push_back(curr);
    }
    return res;
}

long long int abs(long long int n) {
    return (n < 0) ? -n : n;
}

int main() {
    long long int N, K, A, B;
    cin >> N >> K >> A >> B;
    char curr_d;
    vector<string> curr(N, string(1, ' '));
    vector<char> digits;
    vector<string> work;
    vector<long long int> sums;
    vector<long long int> diffs;
    long long int max_num, max_diff = -1;
    for (int i = 0; i < N; i++) {
        cin >> curr_d;
        digits.push_back(curr_d);
        curr[i][0] = curr_d;
    }

    for (int i = 0; i < K - 1; i++) {
        curr = generate(curr, digits);
    }

    for (int i = A - 1; i < B; i++) {
        work.push_back(curr[i]);
    }

    max_num = max(work);
    sums = sum_digits(work);
    for (int i = 0; i < sums.size() - 1; i++) {
        diffs.push_back(abs(sums[i] - sums[i+1]));
    }

    for (int i = 0; i < diffs.size(); i++) {
        if (diffs[i] > max_diff) {
            max_diff = diffs[i];
        }
    }

    cout << max_num << " " << max_diff << endl;

    return 0;
}
