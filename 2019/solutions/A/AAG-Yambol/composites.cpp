#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#define pb push_back
#define mp make_pair
using namespace std;

long long n;

bool prime(long long x)
{
    for(long long i = 2; i * i <= x; i++)
        if(x % i == 0)
            return false;
    return true;
}

vector <long long> precomp = {-1, 5, 26, 110, 1016, 10004, 100004, 1000004, 10000004, 100000004, 1000000004, 10000000004, 100000000004, 1000000000004, 10000000000004, 100000000000004, 1000000000000004, 10000000000000004, 100000000000000016};
int digits(long long x)
{
    int dig = 0;
    while(x > 0)
    {
        x /= 10;
        dig++;
    }
    return dig;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    /*
    freopen("precomp.out", "w", stdout);

    for(int i = 0; i <= 17; i++)
    {
        long long lb = 1, ub;
        for(int j = 1; j <= i; j++)
            lb *= 10;
        ub = lb * 10;
        for(long long j = lb ; j < ub; j += 2)
        {
            if((j % 3 == 2) && !prime(j + 9))
            {
                cout << j << ", ";
                break;
            }
        }
    }
    */


    /*
    for(int i = 2; i < 19; i++)
        cerr << digits(precomp[i]) << " " << precomp[i] % 3 << " " << prime(precomp[i] + 9) << endl;
    */


    cin >> n;
    cout << precomp[digits(n) + 1] << endl;


    return 0;
}
