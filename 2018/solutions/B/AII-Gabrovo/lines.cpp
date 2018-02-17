# include<iostream>
# include<utility>
# include<algorithm>
using namespace std;

pair<int,int> p[1024],p1[1024];
int n;
bool crust(pair<int,int> a, pair<int,int> b, pair<int,int> c)
{
    pair<int,int> v1,v2;
    v1.first=a.first-b.first;
    v1.second=a.second-b.second;

    v2.first=a.first-c.first;
    v2.second=a.second-c.second;

    if(v1.first*v2.second-v2.first*v1.second==0) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>p[i].first>>p[i].second;
        p1[i]=p[i];
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int br=2;
            for(int k=j+1; k<n; k++)
                if(crust(p[i],p[j],p[k])) br++;
            ans=max(br,ans);
        }
    }
    cout<<ans<<endl;
}

/*
19
4 4
3 2
10 2
10 -6
10 -2
1 4
0 -3
-2 -1
-6 2
10 4
14 4
14 2
14 -1
14 -2
14 -4
10 -4
6 -4
6 -2
4 -2

*/
