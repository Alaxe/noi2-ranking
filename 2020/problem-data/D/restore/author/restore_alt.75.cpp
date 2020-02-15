#include<iostream>
using namespace std;

const int N=100000;
int a[N+1],b[N+1],t[N+1];
int n;

int main()
{
    std::ios_base::sync_with_stdio (false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++) cin >> b[i];

    for (int i = 0; i <= n; i++) t[i]=i;

    for (int i = 0; i < n; i++)
    {
        int k = n - b[i] - i;
        a[i] = t[k];
        for(int j=k;j<n;j++) t[j]=t[j+1];
    }

    cout << a[0];
    for (int i = 1; i < n; i++) cout << " " << a[i];
    cout << endl;
}

