#include<iostream>
using namespace std;
int main()
{
    int n, x, i, c0 = 0, c1 = 0, c2 = 0;
    cin >> n >> x;
    if(x == 0) c0 = 1;
    else if(x == 1) c1 = 1;
    else if(x == 2) c2 = 1;
    for(i = n; i >= 1; i--)
    {
        if(i % 2 == 0)
        {
            swap(c1, c2);
        }
        else if(i % 2 != 0)
        {
            swap(c0, c1);
        }
    }
    if(c0) cout << 0 << endl;
    else if(c1) cout << 1 << endl;
    else if(c2) cout << 2 << endl;
    return 0;

}
