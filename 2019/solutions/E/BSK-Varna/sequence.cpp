#include<iostream>
using namespace std;
int main()
{
    long long a=1, b=0, n, br=1;
    cin >> n;
    if(n==1)cout << 1 << endl;
    else
    {
        while(n>a)
        {
            b+=2;
            br+=b;
            a++;
        }
    }
    cout << br << endl;
    return 0;
}
