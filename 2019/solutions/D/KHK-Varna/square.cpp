#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios:sync_with_stdio:(0);
    cin.tie(0);
    cout.tie(0);
    unsigned long long n,nok=1,nok1,a,i;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        nok=nok*a/__gcd(a,nok);
    }
    cout<<nok<<endl;
for(i=1; (i*i)%nok!=0; i++){}
cout<<i<<endl;
}
/**
42
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42
*/
