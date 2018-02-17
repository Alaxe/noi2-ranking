#include <iostream>
using namespace std;

int z;
unsigned long long s, t;
//bool pow = true;

int Pow2(unsigned long long a)
{
    int br = 0;
    while(a>1)
    {
        br++; a/=2;
        //if(a%2==0 && a!=1) pow = false;
    }
    return br;
}

int Binom(int k, int n)
{
    int x = max(k, n - k), y = min(k, n - k);
    int bin = 1;
    for(int i = n; i > x; i--) bin*=i;
    for(int i = 1; i <= y; i++) bin/=i;
    return bin;
}

int Count(int k)
{
    if(k < z + 1) return 0;
    else if(k == z + 1) return 1;
    else return Binom(z+1, k);
}

int main()
{
    cin >> s >> t >> z;

    cout << Count(Pow2(t)) - Count (Pow2(s)) << endl;

    return 0;
}
