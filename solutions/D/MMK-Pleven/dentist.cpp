#include <iostream>
#include <algorithm>
using namespace std;

struct tPac {
    int n, m;
};
int p, q, br, i, start;
tPac a[801];

bool fff (tPac kon, tPac konka) {
    return kon.n < konka.n;
}


int main () {
    while (cin >> p >> q) {
        if (p < 721) {
            a[++br].n = p;
            a[br].m = q;
        }
    }
    sort (a+1, a+br+1, fff);
    start = a[1].n + a[1].m;
    for (i=2; i<=br; i++) {
        if (start < a[i].n) start = a[i].n;
        start = start + a[i].m;
    }
    cout << start - a[br].n << endl;
    return 0;
}
/*
Primeri  :



55 15
185 22
130 10


0 30
720 10
715 20
714 25



0 30
1 30
2 30
3 30
4 30
5 30
6 30
7 30
8 30
9 30
10 30



0 30
29 30
59 30
89 30


0 1
1 2
2 3
3 4
720 15


0 1
1 1
2 1
3 1
4 1
5 1
6 1
7 1
8 1
9 1
10 1
11 1
12 1
13 1
14 1
15 1
16 1
17 1
18 1
19 1
20 1
21 1
42 1
23 1
24 1
25 1
26 1
27 1
28 1
29 1
30 1
41 1
52 1
43 1
44 1
45 1
46 1
47 1
48 1
49 1
50 1
51 1
22 1
53 1
54 1
55 1
56 1
57 1
58 1
59 1
60 1


*/
