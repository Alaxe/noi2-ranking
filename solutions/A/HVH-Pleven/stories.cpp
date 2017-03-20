#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    int first, mul, add, mod;
    vector<long long> st;

    cin >> n >> k;
    cin >> first >> mul >> add >> mod;

    st.push_back(first);

    long long sum = 0;

    for(int i = 0; i < k; i++) {
        st.push_back((st[i-1] * mul + add) % mod);
        sum = sum + st[i];
    }

    cout << sum << endl;

    return 0;
}
