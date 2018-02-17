#include <iostream>
#include <cmath>
using namespace std;

long long convertDecimalToBinary(int);

int main()
{
    int s,t,z;

    cin >> s;
    cin >> t;
    cin >> z;

    int resultCounter =0;
    for(int i = s;i<=t;i++)
    {
        int zeroCounter = 0;
        int x =s;
        int binaryNumber = convertDecimalToBinary(x);
        while(binaryNumber/10 >0)
        {
            if(binaryNumber % 10 == 0)
                zeroCounter++;

            binaryNumber/10;
        }
        if(zeroCounter==z)
            resultCounter++;
    }

    cout<<resultCounter;
    return 0;
}

long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}
