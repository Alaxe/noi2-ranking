#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t,i,n,a[131072],mbr=0,br=0;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        vector<int>v[100001];
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            v[a[i]].push_back(i);
        }
        for(i=1;i<=n;i++)
        {
            br+=v[i].size()-1;
            br+=v[a[i]].size()-1;
            mbr=max(br,mbr);
            br=0;
        }
        cout<<mbr<<endl;
    }
    return 0;
}