#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 1024
using namespace std;

int n;
int a[MAXN];
vector <int> v;

bool Is_Already_Gotten (int x)
{
    int sz=v.size ();
    sort (v.begin (), v.end ());
    int l=0, r=sz-1;
    while (true)
    {
        if (l==r && v[l]==x) return true;
        if ((l==r || l>r) && v[l]!=x) return false;
        int m=(l+r)/2;
        if (v[m]==x) return true;
        if (x<v[m]) r=m;
        else l=m+1;
    }
}

void Solve (int i, int sum, bool b)
{
    if (i==n)
    {
        if (v.size ()==0 || Is_Already_Gotten (sum)==false)
            v.push_back (sum);
        return;
    }
    if (i==n-1 && b==false)
        Solve (i+1, sum+a[i], true);

    else
    {
        Solve (i+1, sum+a[i], true); //take the number A[i]
        Solve (i+1, sum, b); //do not tank the number A[i]
    }
}

int main ()
{
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    Solve (0, 0, false);
    cout<<v.size ()<<endl;
    return 0;
}
