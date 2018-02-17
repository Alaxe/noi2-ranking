#include <bits/stdc++.h>
#define endl '\n'
#define ll unsigned long long
using namespace std;

const int MAX_N = 105;

int n, k, initialDigits[MAX_N];
ll a, b;
vector< int > maxNum;
vector< pair< int, bool > > digitsA, digitsB;

void ComputeDigits(ll num, vector< pair< int, bool > > &res) {
    res.clear();

    num--;

    ll currPwr = 1, cntDigs = 1;
    while(currPwr * n <= num) {
        currPwr *= n;
        cntDigs++;
    }

    bool isReversed = false;
    int digInd = 0;
    while(cntDigs < k) {
        res.push_back({ 0, false });
        digInd++;
        cntDigs++;
    }
    for(digInd; digInd < k; digInd++) {
        int nxtDig = num / currPwr;
        num = num % currPwr;
        currPwr /= n;

        if(isReversed) {
            nxtDig = n - nxtDig - 1;
        }
        res.push_back( { nxtDig, isReversed } );

        if(nxtDig % 2 != 0) {
            isReversed ^= 1;
        }
    }
}

int Check(const vector< pair< int, bool > > &v, int ind, int dig) {
    if(v[ind].second) {
        if(dig > v[ind].first) {
            return -1;
        }
        else if(dig == v[ind].first) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        if(dig > v[ind].first) {
            return 1;
        }
        else if(dig == v[ind].first) {
            return 0;
        }
        else {
            return -1;
        }
    }
}

void GetMaxNumber(int ind, bool isAboveA, bool isUnderB) {
    if(ind == k) {
        return;
    }

    int currMax = -1, maxInd;
    for(int i = 0; i < n; i++) {
        if(isAboveA || Check(digitsA, ind, i) >= 0) {
            if(isUnderB || Check(digitsB, ind, i) <= 0) {
                if(initialDigits[i] > currMax) {
                    currMax = initialDigits[i];
                    maxInd = i;
                }
            }
        }
    }

    bool newIsAboveA = isAboveA || Check(digitsA, ind, maxInd) > 0;
    bool newIsUnderB = isUnderB || Check(digitsB, ind, maxInd) < 0;
    maxNum.push_back(currMax);
    GetMaxNumber(ind + 1, newIsAboveA, newIsUnderB);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> a >> b;

    int maxDiff = 0;
    for(int i = 0; i < n; i++) {
        cin >> initialDigits[i];

        if(i != 0) {
            maxDiff = max(maxDiff, abs(initialDigits[i - 1] - initialDigits[i]));
        }
    }

    ComputeDigits(a, digitsA);
    ComputeDigits(b, digitsB);

    GetMaxNumber(0, 0, 0);

    for(int x : maxNum) {
        cout << x;
    }
    cout << " ";

    if(b - a > n) {
        cout << maxDiff << endl;
    }
    else {
        int ans = 0;
        for(ll i = a + 1; i <= b; i++) {
            ComputeDigits(i, digitsA);
            ComputeDigits(i - 1, digitsB);

            int currAns = 0;
            for(int j = 0; j < k; j++) {
                currAns += abs(initialDigits[digitsA[j].first] - initialDigits[digitsB[j].first]);
            }

            ans = max(ans, currAns);
        }
        cout << ans << endl;
    }

    return 0;
}
