#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int counter = 0;
    for(int i = m; i < 1.11112 * pow(10, n); i++)
    {
        int number = i;
        int sum = 0;
        int a, b;
        while(number > 0)
        {
            a = number % 10;
            b = (number / 10) % 10;
            sum += a;
            if(number % 10 > m)
            {
                sum = 0;
                break;
            }
            if(a < b)
            {
                sum = 0;
                break;
            }
            number /= 10;
        }
        if(sum == n)
        {
            counter++;
        }
    }
    cout<<counter<<endl;

    return 0;

}

