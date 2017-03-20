#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

const int MAXN = 10000001;

int n, k;
long long Ans;
long long F, M, A, Mod;

long long St[MAXN];

void read() {
    int i;

    scanf("%d%d", &n, &k);
    scanf("%lld%lld%lld%lld", &F, &M, &A, &Mod);

    St[0]= F;

    for(i=1; i<n; i++) {
        St[i] = (St[i-1]*M + A) % Mod;
    }
}

void solve() {

    deque<int> D(k);

    int i;

    for(i=0; i<n; i++) {

        if(i >= k) {
            while(!D.empty() && D.front() < (i-k+1))
                D.pop_front();
        }

        while(!D.empty() && St[i] >= St[D.back()])
            D.pop_back();

        D.push_back(i);
        Ans+= St[D.front()];
    }

    printf("%lld\n", Ans);
}

int main() {

    read();
    solve();

    return 0;
}
