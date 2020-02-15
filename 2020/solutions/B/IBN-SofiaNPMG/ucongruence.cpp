#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e6+200;
long long a[maxn];
long long model[maxn];
long long benkovic[61];
bool met[61];
vector <long long> t;
unsigned long long fact (int m, int n) {
    if (n>m)
        return 0;
    unsigned long long a[60], b[60];
    for (int i = n+1; i <= m ;++i) {
        a[i-n-1] = i;
    }
    for (int i = 0; i < m-n; ++i) {
        b[i] = i+1;
    }
    for (int i = 0; i < m-n; ++i) {
        for (int j = 0; j < m-n; ++j) {
            unsigned long long l = __gcd(b[i], a[j]);
            b[i]/=l;
            a[j]/=l;
        }
    }
    unsigned long long prod = 1;
    for (int i = 0; i < m-n; ++i) {
        prod *= a[i];
    }
    return prod;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long N, U;
    cin >> N >> U;
    if(true){
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        met[a[i]]=true;
    }
    for (int i = 0; i < 61; ++i) {
        if (met[i])t.push_back(i);
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < t.size(); ++i) {
        benkovic[t[i]] = i;
    }
    for (int i = 0; i < N; ++i) {
        model[i] = benkovic[a[i]]+1;
        a[i] = model[i];
        //cout << model[i] << " ";
    }
    }
    long long broi = fact(U, t.size());
    long long middle = (broi+1)/2;
    for (int i = 0; i < N; ++i) {
        cout << model[i] + (U-t.size())/2 << " ";
    }
    return 0;
}
