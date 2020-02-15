#include<iostream>
#include<utility>
#include<vector>
#include<set>
#include<algorithm>
#define ULL unsigned long long
using namespace std;

int n, u;
set<int> s;
vector<int> m;
int key[64];
vector<int> order, a;
int br;

ULL calcPermutations()
{
    unsigned long long perm=1;
    for(int i=u; i>=(u-br+1); i--)
        perm*=i;

    for(int i=1;i<=br; ++i)
        perm/=i;

    return perm;
}

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>u;

    int A;
    for(int i=0; i<n; i++)
    {
        cin>>A;
        a.push_back(A);
        if(s.count(a[i])==0) m.push_back(a[i]);
        s.insert(a[i]);
    }

    br=s.size();
    sort(m.begin(), m.begin()+m.size());
    for(int i=0; i<m.size(); ++i)
        key[m[i]]=i;

    for(int i=0; i<n; ++i)
        {order.push_back(key[a[i]]);} //cout<<order[i]<<" ";}

    ULL perm=calcPermutations();
    //cout<<perm<<endl;

    ULL mid=(perm)/2;

    vector<int> current;
    for(int i=0; i<br; ++i)
        current.push_back(i);

    int cnt=0;
    u--;
    while(cnt!=mid)
    {
        int p2=br-1;
        int p1=br-2;

        int refr=0;
        while(current[p2]==u-refr)
        {
            p2=p1;
            p1--;
            refr++;
        }
        current[p2]++;
        p2++;
        while(refr)
        {
            current[p2]=current[p2-1]+1;
            p2++;
            refr--;
        }

        cnt++;
        //cout<<cnt<<endl;
        //for(int i=0; i<br; ++i)
        //    cout<<current[i]<<" ";
        //cout<<endl;
    }

    cout<<current[order[0]]+1;
    for(int i=1; i<n; ++i)
    {
        cout<<" "<<current[order[i]]+1;
    }
    cout<<endl;

    return 0;
}

/*
11 7
2 2 3 7 3 4 4 2 7 2 4
*/
