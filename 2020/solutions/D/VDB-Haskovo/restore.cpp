#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int b[100005], sr[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cin >> b[0];
    for(int i=1; i<n; i++)
    {
        cin >> b[i];
        if(b[i-1]>b[i]) sr[i-1]=0;
        else sr[i-1]=1;
    }
    //5 3 5 5 1 1 2 1 0
    //|<|>|>|<|>|>|<|<|
    //4 6 2 1 8 7 3 5 9

}
