#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
pair<pair< int, int>,pair<int, int> > v[100010];
int used[100005];
int w,h,n,ans=0;
int main()
{
    cin>>w>>h;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y,x1,y1;
        cin>>x>>y>>x1>>y1;
        v[i].first.first=-x;
        v[i].first.second=y;
        v[i].second.first=-x1;
        v[i].second.second=y1;
    }
    sort(v+1,v+n+1);
    for(int i=1;i<=n;i++)
    {
        int y1=v[i].first.second;
        int y2=v[i].second.second;
        int x=-v[i].first.first;
        int br=0;
        for(int j=min(y1,y2);j<=max(y1,y2)-1;j++)
        {
            if(used[j]==0){
            used[j]=1;
            br++;}
        }
        ans+=(w-x+1)*br;

    }
    cout<<ans<<endl;
}
