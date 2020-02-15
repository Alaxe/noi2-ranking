#include <iostream>
using namespace std;
int main ()
{
    int n, ab=0, cd=0, s=0;
    cin >> n;
    char a[n];
    for (int i=0 ; i < n ; i++)
    {
        cin >> a[i];
        s++;
        if (a[i] == 'a' || a[i] == 'b') ab++;
        else cd++;
    }
    for (s = n ; ; s--)
    {
        if (s < 0)
        {
            cout << "0" << endl;
            break;
        }
        if (ab == cd)
        {
            cout << s << endl;
            break;
        }
        else
        {
            if (a[s] == 'a' || a[s] == 'b') ab--;
            else cd--;
        }
    }
    return 0;
}
