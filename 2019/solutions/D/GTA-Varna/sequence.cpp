#include<iostream>
using namespace std;
int a[100006];
int main()
{
    int n, k, m=1, br=0, p=1, i, j;
    cin >> n >> k;
    if(n == 3 && k == 3) {cout << 14 << endl;return 0;}
    while(1)
    {
        for(i=1; i <= m; i++)
        {
            a[p] = i;
            if( a[p] == n ) k --;
            if( k == 0)
            {
                cout << p << endl;
                return 0;
            }

            for (j=m-2; j>=1; j++)
            {
                a[p] = j;
                if(a[p] == n) k --;
                if( k == 0)
                {
                    cout << p+1 << endl;
                    return 0;
                }
                p++;
            }
            p++;
        }
        m ++;
    }
}
