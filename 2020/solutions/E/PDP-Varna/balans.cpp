#include <iostream>
using namespace std;
int main ()
{
    int n;
    char a;
    int brAB;
    int brCD;
    int brB;

    cin >> n;
    cin >> a;
    if(a == 'a' || a == 'b')
    {
        brAB++;
    }

    if(a == 'c' || a == 'd')
    {
        brCD++;
    }

    if(brAB == brCD)
    {
        brB++;
    }


    cout << brB << endl;
    return 0;
}
