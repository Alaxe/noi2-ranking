#include <iostream>
using namespace std;
int main ()
{
    long long a,b;
    cin >> a;
    cin >> b;
    for(a; a>0; a--)
    {
        if(b==1 && a%2==0)
        {
            b=2;
        }
        if(b==1 && a%2==1)
        {
            b=0;
        }
        if(b==2 && a%2==0)
        {
            b=1;
        }
        if(b==0 && a%2==1)
        {
            b=1;
        }
    }
    cout << b;
    cout << endl;
    return 0;
}
