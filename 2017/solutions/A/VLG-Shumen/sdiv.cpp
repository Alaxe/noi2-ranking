#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN= 1024;

string St;
int n, size_St;
long long m;

long long Prev[MAXN], New[MAXN];

void read() {

    int i, j;

    cin>>St;
    size_St= St.size();

    scanf("%d%lld", &n, &m);

    New[(St[0]-'0') % n] = 1;

    for(i=0; i<size_St - 1; i++) {

        for(j=0; j<n; j++) {
            Prev[j] = New[j];
            New[j] = 0;
        }

        for(j=0; j<n; j++) {

            New[j] += Prev[j];
            New[(j*10 + St[i+1] - '0') % n] += Prev[j];

            New[j] %= m;
            New[(j*10 + St[i+1] - '0') % n] %= m;
        }

        New[(St[i+1] - '0') % n] += 1;

        New[(St[i+1] - '0') % n] %= m;
    }

    printf("%lld\n", New[0]);
}

int main() {

    read();
    return 0;
}
