#include <iostream>
using namespace std;
int a[100001], b[100001], c[100001];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = n-1; i > 0; i++)
    {
        for(int j = b[i]; j >= 0; j--)
        {
            do
            {
                a[j]++;
            }
            while(a[j] > a[i]);
        }
    }
    for(int i = 0; i <= n; i++) cout << a[i];
}
