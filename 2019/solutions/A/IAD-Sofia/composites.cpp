#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long ans = n+26-(n%30)+(n%30>26?30:0);
    cout << ans << endl;
}
