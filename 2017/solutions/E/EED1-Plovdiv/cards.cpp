#include <iostream>
using namespace std;

int main()
{
    int n,ai,bi,a,b;
    int br = 0;
    int max1 = 0;
    cin >> n;
    cin >> ai >> bi;
    a = ai;
    b = bi;
    for (int i = 1; i < n; i++)
    {
        cin >> ai >> bi;
        if (a >= ai && b >= bi)
        {
            br++;
        }
        else if (a >= bi && b >= ai)
        {
            br++;
        }
        else if (ai >= b && bi >= a) br++;
        else if (ai >= a && bi >= b) br++;

        else br = 0;
        if (br > max1) max1 = br;
        a = ai;
        b = bi;
    }
    cout << max1 << endl;
}
