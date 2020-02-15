#include <iostream>
using namespace std;
int main ()
{
    int a=0, b=1, c=2;
    int a1=0, a2=0, a3=0;
    int n, x;
    int br;

    cin >> n >> x;

    if(x==a)
    {
        a1=a1+1;
    }
    if(x==b)
    {
        a2=a2+1;
    }
    if(x==c)
    {
        a3=a3+1;
    }

    for(br=n; br >= 0; br--)
    {

        if(br%2 == 0)
        {
            if(a1 == 1)
            {
                a2 = 1;
                a1 = 0;
            }
            else if (a2 == 1 )
            {
                a1 = 1;
                a2 = 0;
            }


        }
        else
        {
            if(a2 == 1)
            {
                a3 = 1;
                a2 = 0;
            }
            if(a3 == 1)
            {
                a2 = 1;
                a3 = 0;
            }
        }

    }
    if(a1 == 1)
    {
        cout << a << endl;
    }
    else if(a2 == 1)
    {
        cout << b << endl;
    }
    else if (a3 == 1)
    {
        cout << c << endl;
    }
    return 0;
}
