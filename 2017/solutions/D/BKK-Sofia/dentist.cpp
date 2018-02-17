#include<iostream>
using namespace std;

int main () {
    int a, b, c, d, e ,f;
    cin >> a >> b >> c >> d >> e >> f;
    if (a>c) {swap(a, c); swap(b, d);}
    if (a>e) {swap(a, e); swap(b, f);}
    if (c>e) {swap(e, c); swap(f, d);}
    int time = a+b;
    if (c<time) {time+=d;}
    else {time = c+d;}
    if (e<time) {time+=f;}
    else {time = e+f;}
    cout << time-e << endl;
    return 0;
}
