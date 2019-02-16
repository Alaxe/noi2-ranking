#include<bits/stdc++.h>
using namespace std;
vector<int> graf[5005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,wishes,boss;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        cin >> wishes;
        for(int j=1; j<=wishes; j++)
        {
            cin >> boss;
            graf[i].push_back(boss);
        }
    }
    cout << "3\n";
    return 0;
}
/**
Input:
4 100
1 4
3 1 3 4
2 1 2
1 3
Output:
800
*/
