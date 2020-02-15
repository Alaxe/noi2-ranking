#include<iostream>
using namespace std;
int main()
{
    int n, u, v, arr[100], voda = 0, Max = 0, iMax, iMax2, Max2 = 0, iMax3;
    cin >> n >> u >> v;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(Max < arr[i])
        {
            iMax = i;
            Max=arr[i];
        }
    }

    iMax2 = iMax;
    while(iMax2 != 0)
    {
        Max2 = 0;
        for(int i = 0; i < iMax2; i++)
        {
            if(Max2 < arr[i])
            {
                iMax3 = i;
                Max2 = arr[i];
            }
        }
        voda += Max2*(iMax2-iMax3);
        iMax2 = iMax3;
    }

    iMax2 = iMax;
    while(iMax2 != n-1)
    {
        Max2 = 0;
        for(int i = iMax2+1; i < n; i++)
        {
            if(Max2 < arr[i])
            {
                iMax2 = i;
                Max2 = arr[i];
            }
        }
        voda += Max2*(iMax2-iMax);
    }
    voda *= u*v;
    cout << voda << endl;
    return 0;
}
