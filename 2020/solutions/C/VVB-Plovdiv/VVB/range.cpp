#include<bits/stdc++.h>
using namespace std;
long long a[100001],n,m,ans,c,c1,begi,maxi;
struct s
{
    long long x,y;
} b[100000];
bool cmp(s l,s p)
{
    if(l.x>p.x)
        return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    long long i,j;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    cin>>m;
    for(i=0; i<m; i++)
    {
        cin>>b[i].x>>b[i].y;
    }
    sort(b,b+m,cmp);
    i=0;
    j=0;
    long long begi=0;
    while(j<m)
    {
        while(a[i]<=b[j].y&&i<=n)
        {
            if(a[i]>=b[j].x)
            {
                if(!begi)
                    begi=i;
                ans++;
            }
            i++;
        }
        cout<<ans<<endl;
        ans=0;
        j++;
        i=begi;
        begi=0;
    }

//dp(b[0].x,b[0].y,1);
    return 0;
}
/*
6
9 1 3 10 3 4
3
1 4
9 12
15 20
1 4
9 12
15 20
*/
