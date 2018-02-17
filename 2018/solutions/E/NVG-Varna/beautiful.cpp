//beautiful
#include<iostream>
using namespace std;


int pow(int b, int p)
{
    int o = b;
    for(int i = 1; i < p;i++)
    {
        o *= b;
    }
    if(p == 0) o = 1;
    return o;
}


int main()
{
    long long n, k,m,b;
    b = 0;
    cin >> n >> k;
    for(int i = pow(10,n - 1);i < pow(10,n);i++)
    {
        if(i % k == 0)
        {
            b = i;
            break;
        }
    }
    if(b != 0)cout << b;
    else cout << "NO";
    cout << endl;
    return 0;
}
