#include <bits/stdc++.h>

using namespace std;
int interactions = 0;
vector <string> generate(vector<string> prev, vector<string> digits) {
    vector <string> next;

    for (int i = 0; i < digits.size(); i++) {
        interactions++;
        if (i % 2 == 0) {
            for (int j = 0; j < prev.size(); j++) {
                interactions++;
                next.push_back(digits[i] + prev[j]);
            }
        } else {
            for (int j = prev.size() - 1; j >= 0; j--) {
                interactions++;
                next.push_back(digits[i] + prev[j]);
            }
        }
    }

    return next;
}

vector<string> append(vector<string> a, vector<string> b) {
    for (int i = 0; i < b.size(); i++) {
        a.push_back(b[i]);
    }

    return a;
}
/*
vector<string> genNumber(vector<string> digits, int length, string number) {
    cout << "called get number with " << number << "\n";
    vector<string> next;
    interactions++;
    int nSize = number.size();
    bool reversed = used[nSize];
    used[nSize] = !used[nSize];

    vector<string> dd = digits;
    if (reversed)
        reverse(dd.begin(), dd.end());

    for (int i = 0; i < dd.size(); i++) {
        interactions++;
        string a = number + dd[i];

        if (a.size() < length)
            next = append(next, genNumber(digits, length, a));
        else {
            cout << "push back\n";
            next.push_back(a);
        }
    }

    return next;
}

vector<string> optnumber(vector<string> digits, int length, string number) {
    vector<string> next;
    int levels = length, currentLevel = 2;
    fill(used, used + 100, false);

    return next;
}

vector <string> generateOpt(vector<string> digits, int length) {
    vector <string> next;

    for (int i = 0; i < digits.size(); i++) {
        next = append(next, genNumber(digits, length, digits[i]));
    }

    return next;
}
*/
bool used[100] = { false };
int N, K, A, B;
int p, numberFromSequence, firstDigit;

string buildFirstNumber(vector<string> digits, int number) {
    string a = digits[firstDigit];

    for (int i = 1; i < K; i++) {
        int changeFrequency = p / K;
        p = changeFrequency;
        int l = ceil((double)changeFrequency / (double)K);
        int currentDigit = l % 2 != 0 ? ((numberFromSequence + 1) % K): K - ((numberFromSequence + 1) % K);
        cout << l << " level " << i << " freq " << changeFrequency << " " << currentDigit << "\n";
        a += digits[currentDigit];
    }

    return a;
}

void guessNumber(vector<string> digits, int number) {
    p = pow(N, K - 1);
    numberFromSequence = (number - 1) % p;
    firstDigit = (number - 1) / p;
    // int secondDigit = ;

    cout << firstDigit << " " << numberFromSequence <<" => " << digits[firstDigit] << "; the number is " << buildFirstNumber(digits, number) << "\n";
}

int main() {

    cin >> N >> K >> A >> B;
    vector<string> digits;
    vector<string> prev;
    string digit;

    for (int i = 0; i < N; i++) {
        cin >> digit;
        digits.push_back(digit);
        prev.push_back(digit);
    }

    vector<string> next = prev;
    guessNumber(next, 8);

    /*next = generateOpt(digits, K);
    cout << "OPT INTERACTIONS: " << interactions << "\n";
    interactions = 0;*/

    for (int i = 0; i < K - 1; i++) {
        next = generate(next, digits);
    }
    cout << "INTERACTIONS: " << interactions << "\n";

    for (string a: next) {
        cout << a << " ";
    }
    cout << "\n";

    return 0;
}
