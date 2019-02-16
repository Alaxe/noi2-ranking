#include <bits/stdc++.h>
using namespace std;
int sum_of_even(int from, int c)
{
    if(c % 2 == 0)
        return (c * 2 + from) * c / 2;
    return ((c - 1) * 2 + from) * (c - 1) / 2 + (c * 2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    if(k % 2 == 0)
        cout << (n * (n - 1) + 1) + (k / 2) * (n * 2 - 1) + sum_of_even(2, k / 2 - 1);
    else
        cout << (n * (n - 1) + 1) + (k / 2) * (n * 2 - 1) + sum_of_even(2, k / 2);

    cout << endl;


}
