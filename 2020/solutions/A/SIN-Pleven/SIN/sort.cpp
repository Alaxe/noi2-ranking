#include<iostream>
#include<vector>
#include<cstdio>
#include<climits>
using namespace std;
int n;
vector<int> numbs;
vector<int> diffs;
long long ans;

int main ()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        int x;
        scanf("%d", &x);
        numbs.push_back(x);
        diffs.push_back(0);
    }
    int mn = numbs[n-1];
    for (int i=n-2; i>=0; i--)
    {
        if (numbs[i] <= mn)
        {
            mn = numbs[i];
        }
        else
        {
            diffs[i] = mn - numbs[i];
            numbs[i] = mn;
        }
    }
//    for (int i=0; i<n; i++) cout<<numbs[i]<<" ";
//    cout<<endl;
//    for (int i=0; i<n; i++) cout<<diffs[i]<<" ";
//    cout<<endl;

    for (int i=0; i<n; i++)
    {
        if (diffs[i] >= 0) continue;
        while (1)
        {
            if (diffs[i] >= 0) break;
            int curn = numbs[i], pass=0, flag = false;
            for (int j=i; j<=n; j++)
            {
                if (numbs[j] != curn) break;
                if (diffs[j] < 0) pass++;
                else pass--;

                if (pass < 0) flag = true;
            }
            if (flag == true) break;
            if (pass == 0) break;

            for (int j=i; j<=n; j++)
            {
                if (numbs[j] != curn) break;
                numbs[j]++;
                diffs[j]++;
            }
        }
    }

    for (int i=0; i<n; i++) ans+=abs(diffs[i]);

//    for (int i=0; i<n; i++) cout<<numbs[i]<<" ";
//    cout<<endl;
//    for (int i=0; i<n; i++) cout<<diffs[i]<<" ";
//    cout<<endl;

    cout<<ans<<endl;
    return 0;
}
/**
10
3 7 4 9 5 2 2 8 4 9

40
4 8 3 9 5 8 4 3 5 9 15 9 4 8 5 9 3 8 5 3 12 8 5 9 4 8 18 4 8 3 9 5 3
4
5
6
19
21
4
68
*/
