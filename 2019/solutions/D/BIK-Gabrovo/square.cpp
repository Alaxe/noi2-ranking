#include <iostream>
using namespace std;
int main ()
{
    int n, t [10002];
    cin >> n;
    int maxs, br=0;
    for (int i=0; i<n; i++)
    {
        cin >> t[i];
    }
    maxs=t[0];
    for (int i=0; i<n; i++)
    {
        if (t[i]>maxs)
            maxs=t[i];
    }
//-------------------------------------
    int x, ch=maxs;
    do
    {
        x=n;
        ch=ch+maxs;
        for (int i=0; i<n; i++)
        {
            if (ch%t[i]==0)
                x--;
        }
        if (x==0)
            break;
    }
    while (true);
//-------------------------------------


    int c=1;
    do
    {
        c++;
        if ((c*c)%ch==0)
        {
            cout << c << endl;
            return 0;
        }
    }
    while (true);
    return 0;
}
