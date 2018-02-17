#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
long long cps[200][200];
constexpr long long mod = 1000000007;
long long countPS(const string& str)
{
    int N = str.size();
    //memset(cps, 0, sizeof(cps));
    for (int i=0; i<N; i++)
        cps[i][i] = 1;
    for (int L=2; L<=N; L++)
    {
        for (int i=0; i<N; i++)
        {
            int k = L+i-1;
            if (str[i] == str[k])
            {
                cps[i][k] = cps[i][k-1] +
                            cps[i+1][k] + 1;
                cps[i][k]%=mod;
            }
            else
            {
                cps[i][k] = cps[i][k-1] +
                            cps[i+1][k] -
                            cps[i+1][k-1];
                cps[i][k]%=mod;
            }
        }
    }
    return cps[0][N-1]%mod;
}

int main()
{
    string str;
    cin >> str;
    cout << abs(countPS(str)) << endl;
    return 0;
}
