#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    int n, k;
    cin >> n >> k;
    if (k==1 || k==n)
    {
        cout << 1 << endl;
        return 0;
    }
    if (k==2 || k==n-1)
    {;
        cout << n-1 << endl;
        return 0;
    }
    if (k==3 || n-k==2)
    {
        int s=0;
        for (int i=n-2; i>=0; i--)
        {
            s=s+i;
        }
        cout << s << endl;
        return 0;
    }
    if (k==4 || n-k==3)
    {
        int c=n-1;
        int s=0;
        for (int i=1; i<c-1; i++)
        {
            for (int j=i; j>=0; j--)
                s=s+j;
        }
        cout << s << endl;
        return 0;
    }

    int g=min(k-1, n-k+1);
    cout << ((n-1)-(g-1))*(n-1) << endl;
    return 0;
}
