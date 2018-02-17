#include <bits/stdc++.h>
using namespace std;

set<unsigned long long> sorted;
queue<unsigned long long> ordered;

int main()
{
    int K, N, first, mul, add, mod;
    unsigned long long curr, result;

    cin>>N>>K>>first>>mul>>add>>mod;
    /*N = 10000000;
    K = 5000000;
    first = 20;
    mul = 3;
    add = 17;
    mod = 1000000007;*/

    curr = first;
    result = first;

    sorted.insert(curr);
    ordered.push(curr);

    for (int i=1;i<K;i++)
    {
        curr = (curr * mul + add) % mod;
        sorted.insert(curr);
        ordered.push(curr);
        result += *prev(sorted.end());
    }

    for (int i=K;i<N;i++)
    {
        curr = (curr * mul + add) % mod;
        unsigned long long kek = ordered.front();
        ordered.pop();
        sorted.erase(kek);

        ordered.push(curr);
        sorted.insert(curr);

        result+=*prev(sorted.end());

    }


    cout<<result<<endl;


    return 0;
}
