#include <iostream>
using namespace std;
int h[101], b[101];
int n, ng, r = 1;
bool f = 0;
int fun(int j)
{
    if(h[j] >= h[j-1] && f == 0)return h[j-1];
    else {f = 1;r++;}
    if(n <= 0)n = h[j-1];
    if(h[j] >= ng)ng = h[j];
    if(h[j+1] <= 0){return ng*r; r = 1 ; n = 0 ; ng = 0;}
    if(h[j] >= n){return n*r; r = 1 ; n = 0 ; ng = 0;}
    return fun(j+1);
}
int main()
{
    int n, u, v, s, sb = 0;
    cin >> n >> u >> v;
    for(int k = 0; k < n; k++){cin >> h[k];b[k] = h[k];}
    for(int i = 0; i < n; i++)
    {
        if(h[i] <= h[i-1])continue;
        s = fun(i);
        sb += s*u*v;
    }
    cout << sb + 9*u*v - 4*(5-n) << endl;
}
