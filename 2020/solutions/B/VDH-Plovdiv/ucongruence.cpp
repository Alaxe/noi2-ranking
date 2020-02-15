#include <iostream>
#include <vector>
using namespace std;
unsigned long long comb(int n, int k)
{
    if (k>n/2) k=n-k;
    unsigned long long ans=1;
    for (int i=0; i<k; i++)
    {
        ans=ans*(n-i);
        ans=ans/(i+1);
    }
    return ans;
}
vector <int> v[64];
vector <int> b;
int otg[1000100];
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(false);
    cout.tie(false);
    int n, u;
    cin>>n>>u;
    int br=0;
    for (int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        if (v[a].empty()) br++;
        v[a].push_back(i);
    }
    int last=0;
    unsigned long long m=(comb(u, br)+1)/2;

    for (int k=1; k<=br; k++)
    {
        if (k==br)
        {
            b.push_back(last+m); break;
        }
        for (int i=last+1; i<=u; i++)
        {
            unsigned long long t=comb(u-i, br-k);
            if (m>t) {m=m-t; continue;}
            //if (m==t) {}//!
            if (m<=t)
            {
                b.push_back(i);
                last=i;
                break;
            }
        }
    }
    int j=0;
    for (int i=1; i<=u; i++)
    {
        if (v[i].empty()) continue;
        else
        {
            for (int l=0; l<v[i].size(); l++)
            {
                otg[v[i][l]]=b[j];
            }
            j++;
        }
    }
    for (int i=0; i<n; i++)
        cout<<otg[i]<<" ";
    cout<<endl;
}

