#include <iostream>
#include <algorithm>
#define MAXN 100002
using namespace std;

int t;
int ans[10];

bool cmp (int x, int y)
{
    return x>y;
}

void Test (int pos)
{
    int n;
    int a[MAXN];
    cin>>n;
    for (int i=0; i<=n; i++)  //to zero
        a[i]=0;

    for (int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    sort (a, a+n, cmp);
    ans [pos]=a[0]+1;
}

void Print ()
{
    for (int i=0; i<t; i++)
        cout<<ans[i]<<endl;
}

int main ()
{
    cin>>t;
    for (int i=0; i<t; i++)
        Test (i);

    Print ();
    return 0;
}
