#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int purvoChPoGol[100001];
vector <int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort (v.begin(), v.end());
    for (int i=1, k=0;i<=100000 && k<n;)
    {
        if (v[k]>=i)
        {
            purvoChPoGol[i++]=k;
        }
        else
        {
            ++k;
        }
    }
    cin>>n;
    for (int i=0;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        if (b>=v.back() && a<=v.back())
        {
            cout<<v.size()-purvoChPoGol[a];
        }
        else if (a<=v.back())
            if (b==v[purvoChPoGol[b]])
                cout<<purvoChPoGol[b]-purvoChPoGol[a]+1;
            else
                cout<<purvoChPoGol[b]-purvoChPoGol[a];
        else cout<<0;
        cout<<'\n';
    }


    return 0;
}
/*
6
9 1 3 10 3 4
3
1 4
9 12
15 20


6
9 1 3 10 3 4
3
1 10
2 10
4 10
*/
