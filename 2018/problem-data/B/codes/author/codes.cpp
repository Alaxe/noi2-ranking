#include <iostream>
#include <vector>
using namespace std;

long long n, k, a, b;
const int MAXN = 101;
const int MAXK = 10001;
const unsigned long long INF = 10 + 1e18L;
int digits[MAXN];

unsigned long long c[MAXK];
int largest[MAXK];

bool rev = false;
bool secondCase = false;

inline int dig(int i) {
    if(rev) return digits[n-1-i];
    else return digits[i];
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

void findMax(long long a, long long b, int largestIdx, int i) {
    while (largestIdx < k) {
        while(i>=0 && a/c[i] == b/c[i]) {
                //cout << dig(b/c[i]) << endl;
            if(secondCase && largest[largestIdx] > dig(b/c[i])) {
                return;
            } else if(secondCase && largest[largestIdx] < dig(b/c[i])) {
                secondCase = false;
            }

            largest[largestIdx] = dig(b/c[i]);
            largestIdx++;

            if( (!rev && (a/c[i])%2 == 1) || (rev && (n-1-a/c[i])%2 == 1))  {
                rev = !rev;
            }
            a = a%c[i];
            b = b%c[i];
            i--;
        }

        if(!(largestIdx < k)) break;
        //cout << "c[i]=" << c[i] << endl;
        int ai = a/c[i];
        int bi = b/c[i];
        int besti = ai;
        for(int j = ai; j <= bi; j++) {
            if(dig(j) > dig(besti)) {
                besti = j;
            } else if(dig(j) == dig(besti) && j != bi) {
                besti = j; // keep the best in the middle
            }
        }

        if(secondCase && largest[largestIdx] > dig(besti)) {
            return;
        } else if(secondCase && largest[largestIdx] < dig(besti)) {
            secondCase = false;
        }
        largest[largestIdx] = dig(besti);
        largestIdx++;

        if (besti == ai) {
            if (dig(ai) == dig(bi)) {
                findMax(a%c[i], c[i] - 1, largestIdx, i-1);
                secondCase = true;
                findMax(0, b%c[i], largestIdx, i-1);
                return;

            } else {
                if( (!rev && (a/c[i])%2 == 1) || (rev && (n-1-a/c[i])%2 == 1))  {
                    rev = !rev;
                }
                a = a%c[i];
                b = c[i] - 1;
                i--;
            }
        } else if (besti == bi) {
            if( (!rev && (b/c[i])%2 == 1) || (rev && (n-1-b/c[i])%2 == 1))  {
                rev = !rev;
            }
            a = 0;
            b = b%c[i];
            i--;
        } else {
            int maxd = -1;
            for(int j = 0; j < n; j++) {
                maxd = max(maxd, digits[j]);
            }
            while(largestIdx < k) {
                if(secondCase && largest[largestIdx] > maxd) {
                    return;
                } else if(secondCase && largest[largestIdx] < maxd) {
                    secondCase = false;
                }
                largest[largestIdx] = max(largest[largestIdx], maxd);
                largestIdx++;
            }
        }
    }
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

    findMax(a, b, 0, k-1);

    for(int j = 0; j < k; j++) {
        cout << largest[j];
    }
    cout << " " << diff;
    cout << endl;
}
