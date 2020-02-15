#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,  x, a=0, b=1, c=2;
    cin >>  n >> x;
    for (long long i=n;  i>=1; i--)
    {
        if (i%2==0) swap(b,c);
        else if (i%2==1) swap (a,b);
        if (a==x)  {cout << 0 <<endl; return 0;}
        else if (b==x) {cout << 1 <<endl; return 0;}
        else if (c==x) {cout << 2 <<endl; return 0;}
    }
}
