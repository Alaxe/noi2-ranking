#include <iostream>

using namespace std;

int a, n;

struct patient
{
    int come;
    int op;
};
patient ar[1024];


void sort_struct()
{
    for(int i = 0;i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(ar[i].come > ar[j].come)
            {
                swap(ar[i].come, ar[j].come);
                swap(ar[i].op, ar[j].op);
            }
        }
    }

}

int main()
{

    int k = 0;
    while(cin >> a)
    {
        ar[k].come = a;
        cin >> a;
        ar[k].op = a;
        k++;
    }
    n = k;


    sort_struct();


    int ans = 0;

    for(int i = 0;i < n; ++i)
    {
        if(!(ans >= ar[i].come))
			ans = ar[i].come + ar[i].op;
        else
        {
			ans += ar[i].op;
        }
    }
    cout << ans - ar[n - 1].come <<endl;
    return 0;
}

