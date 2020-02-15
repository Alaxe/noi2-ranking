#include <iostream>
using namespace std;

int br[100001];

int main ()
{
    int n;
    cin >> n;
    int t[n];
    for (int i=0; i<n; i++)
    {
        cin >> t[i];
    }
    int m;
    cin >> m;
    int s1[m], s2[m];
    for (int i=0; i<m; i++)
    {
        cin >> s1[i] >> s2[i];
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (t[i]>=s1[j] && t[i]<=s2[j])
                br[j]++;
        }
    }
    for (int i=0; i<m; i++)
        cout << br[i] << endl;
    return 0;
}
