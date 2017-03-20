#include <iostream>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    int a[N];
    for(int i=0; i<N; i++)
    {
        cin >> a[i];
    }
    cout << (N-1)*(N-2) << endl;
}
