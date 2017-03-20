#include<iostream>
using namespace std;

    int a[1024];
    int b[1024][1024];

int main()
{
    int n, br = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        int k = 0;
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] < a[j])
            {
                b[i][k] = j;
                k++;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < n; k++)
        {
            if(b[i][k] != 0)
            br++;
        }
    }
    cout << br;



return 0;
}
