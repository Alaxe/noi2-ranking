#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string stepen;
    cin >> stepen;

    long long dve = 2;
    string degree;
    int i;
    for(i = 1; stepen != degree; i++)
    {
        long long dve1 = dve;
        long long n = 1;
        while(n*10 < dve) n *= 10;

        while(dve1 > 0)
        {
            char ch = dve1/n + '0';
            degree = degree + ch;
            dve1 %= n;
            n /= 10;
        }
        dve *= 2;
        if(stepen == degree) break;
    }
    cout<<i<<endl;
}
