#include <iostream>

using namespace std;

int main()
{
    int n, m, c = 0, cc = 0, d = 0;
    cin>>n>>m;
    if(n == 0 || n == 1 || n == 2)
    {
        std::cout<<n<<endl;
        return 0;
    }
    int a[n];
    for(int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    while(d != -1)
    {
        int k = m;
        if(d != 0)
            k = a[d - 1];
        if(n < m)
            k = n;
        if(a[d] != 0)
        {
            if(a[d] == 1)
            {
                cc -= a[d];
                a[d] = 0;
                d--;

                continue;
            }
            else
            {
                cc -= a[d];
                a[d]--;
                k = a[d];
            }
        }
        for(int i = k; i >= 1; i--)
        {
            cc += i;
            if(cc < n)
            {
                a[d] = i;
                d++;
                break;
            }
            else if(cc == n)
            {
                a[d] = i;
                c++;
                a[d] = 0;
                if(i == 1)
                {
                    d--;
                    cc -= i;
                    break;
                }
            }
            cc -= i;
        }
        if(a[0] <= 2)
            break;
    }

    cout << c + n / 2 + 1 << endl;

    return 0;
}
