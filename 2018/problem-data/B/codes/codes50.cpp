#include <iostream>
#include <vector>
using namespace std;

long long n, k, a, b;
const int MAXN = 101;
const int MAXK = 10001;
const unsigned long long INF = 10 + 1e18L;
int digits[MAXN];

unsigned long long c[MAXK];


bool rev = false;
bool secondCase = false;

inline int dig(int i) {
    if(rev) return digits[n-1-i];
    else return digits[i];
}

vector<int> get(long long a) {
    vector<int> res;

    bool rev = false;
    for(int i = k-1; i >= 0; i--) {
        if(rev) res.push_back(digits[n-1-(a/c[i])]);
        else res.push_back(digits[a/c[i]]);

        if( (!rev && (a/c[i])%2 == 1) || (rev && (n-1-a/c[i])%2 == 1))  {
            rev = !rev;
        }

        a = a%c[i];
    }
    return res;
}

int getSum(long long a) {
    int sum = 0;

    bool rev = false;
    for(int i = k-1; i >= 0; i--) {
        if(rev) sum += digits[n-1-(a/c[i])];
        else sum += digits[a/c[i]];

        if( (!rev && (a/c[i])%2 == 1) || (rev && (n-1-a/c[i])%2 == 1))  {
            rev = !rev;
        }

        a = a%c[i];
    }

    return sum;
}

vector<int>& max(vector<int>& x, vector<int>& y) {
    for(int i = 0; i < x.size(); i++) {
        if(x[i] < y[i]) return y;
        if(x[i] > y[i]) return x;
    }
    return x;
}

int main() {
    cin >> n >> k >> a >> b;
    a--;b--;

    for(int i = 0; i < n; i++)
        cin >> digits[i];

    c[0] = 1;
    for(int i = 1; i <= k; i++) {
        c[i] = c[i-1]*n;
        if (c[i]/n != c[i-1]) { // overflow
            c[i] = INF;
        }
    }

    int diff = -1;
    for(long long i = a; i < min(a+2*n, b); i++) {
        int cdiff = getSum(i) - getSum(i+1);
        if(cdiff < 0) cdiff *= -1;
        if(cdiff > diff) diff = cdiff;
    }

    vector<int> largest = get(a);
    for(long long i = a+1; i <= b; i++) {
        largest = max(largest, get(i));
    }

    for(int j = 0; j < k; j++) {
        cout << largest[j];
    }
    cout << " " << diff;
    cout << endl;
}
