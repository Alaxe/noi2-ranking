#include<iostream>
#include<vector>
using namespace std;

const int N=100000;
int a[N+1],b[N+1];
int n;

int main()
{
    std::ios_base::sync_with_stdio (false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> b[i];

    vector<int> t;
    for (int i = 0; i <= n; i++) t.push_back(i);

    for (int i = 1; i <= n; i++)
    {
        int k = t.size() - 1 - b[i];
        a[i] = t[k];
        t.erase(t.begin() + k);
    }

    cout << a[1];
    for (int i = 2; i <= n; i++) cout << " " << a[i];
    cout << endl;
}

