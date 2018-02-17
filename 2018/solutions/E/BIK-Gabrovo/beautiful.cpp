#include <iostream>
using namespace std;
int main ()
{
    long long k, start, i, ch;
    int n;
    cin >> n >> k;
    if (n==1)
        start=1;
    if (n==2)
        start=10;
    if (n==3)
        start=100;
    if (n==4)
        start=1000;
    if (n==5)
        start=10000;
    if (n==6)
        start=100000;
    if (n==7)
        start=1000000;
    if (n==8)
        start=10000000;
    if (n==9)
        start=100000000;
    if (n==10)
        start=1000000000;
    if (n==11)
        start=10000000000;
    if (n==12)
        start=100000000000;
    if (n==13)
        start=1000000000000;
    if (n==14)
        start=10000000000000;
    if (n==15)
        start=100000000000000;
    if (n==16)
        start=1000000000000000;
    if (n==17)
        start=10000000000000000;
    if (n==18)
        start=100000000000000000;

    if (start%k==0)
    {
        cout << start << endl;
        return 0;
    }
    if (k>start)
    {
        cout << "NO" << endl;
        return 0;
    }

    do
        start++;
    while (start%k!=0);
    cout << start << endl;

    return 0;
}
