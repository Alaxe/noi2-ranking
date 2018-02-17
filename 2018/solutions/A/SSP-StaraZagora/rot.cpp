#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
using ull = unsigned long long;

ull solve(int b, ull M, int n)
{
    if(M%(b-1)) return 0;
    M/=b-1;
lbl:
    ull ones=0, t=1, res;
    for(int i=0; i<n-1; ++i) ones=b*ones+1;
//cout << ones << endl;
    for(int i=0; i<n-1; ++i) t*=b;
    res=t+M+ones;
    if(M+ones>=t)
    {
        ++n;
        goto lbl;
    }
    return res;
}

string decToR(ull n, int radix)
{
    if(!n) return "0";
    string res;
    const char *digit="0123456789ABCDEF";
    while(n)
    {
        auto t=lldiv(n,radix);
        res.push_back(digit[t.rem]);
        n=t.quot;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    int b;
    string M;
    cin >> b;
    for(int i=0; i<4; ++i)
    {
        cin >> M;
        cout << decToR(solve(b,strtoull(M.c_str(),nullptr,b),M.size()),b) << endl;
    }
}
