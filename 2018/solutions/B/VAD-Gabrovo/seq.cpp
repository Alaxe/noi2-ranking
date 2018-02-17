#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

long long br=0;

void Rec (int last, int sum_left)
{
    if (sum_left==0)
    {
        br++;
        return;
    }
    for (int i=1; i<=min(last, sum_left); i++)
        Rec (i, sum_left-i);
}

int main ()
{
    int n, m;
    cin>>n>>m;
    Rec (m, n);
    cout<<br<<endl;
    return 0;
}
