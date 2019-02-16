#include <iostream>
#include <cmath>
using namespace std;
unsigned long long NOD(unsigned long long a, unsigned long long b)
{
    int M = max(a,b), m = min(a,b);
    if(a > 0 && b > 0)return NOD(M%m,m);
    return M;
}
unsigned long long arr[10000];
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
        cin >> arr[i];
    unsigned long long nok = 1;
    for(int i = 0 ; i < n ; ++i)
    {
        unsigned long long stuff = nok;
        nok *= arr[i];
        nok /= NOD(stuff,arr[i]);
    }
    for(int i = 1 ; 1 ; ++i)
    {
        unsigned long long a = i*nok;
        unsigned long long res = sqrt(floor(a));
        if(sqrt(a) == res){
            cout << res << '\n';
            return 0;
        }
    }
    return 0;
}
