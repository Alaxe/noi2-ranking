#include<iostream>
using namespace std;

int main ()
{
    long long N, br_beauti = 0, i = 11;
    cin >> N;
    if(N < 10)
    {
        cout << N << endl;
    }
    else
    {
        br_beauti = N / 11;
    cout << br_beauti + 9 << endl;
    }
    return 0;
}
