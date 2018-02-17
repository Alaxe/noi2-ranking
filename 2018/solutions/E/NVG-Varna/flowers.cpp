//zad3
#include<iostream>
using namespace std;


int main()
{
    int n,q,br,m;
    cin >> n;
    int* h = new int [n];
    for(int i = 0;i < n;i++)cin >> h[i];
    cin >> q;
    br = 0;
    m = 0;
    for(int i = 0;i < n; i++)if(h[i] > m)m = h[i];
    for(int i = 0;i < n; i++)
    {
        br += (m - h[i]) * q;
    }
    cout << br << endl;
}
