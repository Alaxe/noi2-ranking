#include <iostream>
using namespace std;
int main ()
{
    int a = 1 , n , br = 0, c, b;
    cin >> n;
    for( a = 1; a <= n ; a++)
    {
        c = a;
        b = a%10;

        while(c != 0)
        {
            c = c/10;
            if(c <= 0)
            {
                break;
            }
            b = b * 10 + c%10;
        }
        if(b == a)
        {
            br++;
        }

    }
    cout << br << endl;

    return 0;
}








