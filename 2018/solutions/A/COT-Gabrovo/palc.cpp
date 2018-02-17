#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
int n,ans,m=1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    n=s.size();
    for (int i=0; i<n; i++)
        m*=2;
    for (int i=1; i<m; i++)
    {
        int x=i;
        string z="",p;
        for (int j=0; j<n; j++)
        {
            if (x%2)
                z=z+s[j];
            x/=2;
        }
        p=z;
        reverse(p.begin(),p.end());
        if (z==p)
            ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
