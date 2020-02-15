# include <bits/stdc++.h>
using namespace std;
struct elements
{
    int id;
    int x;
    int w;
};
struct positions
{
    int prev;
    int next;
    int st;
};
positions pos[65];
elements el[1000005];
long long dp[65][65];
int ansers[65];
int first[1000006];
bool cmp(elements i, elements j)
{
    return i.x<j.x;
}
void calc(int n,int m)
{
    int i,j,t;
    dp[0][0]=1;
    for(i=1;i<=m;i++)
        dp[0][i]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
           // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);*
    cout.tie(NULL);
int n,u;
cin>>n>>u;
int i,j;
for(i=1;i<=n;i++)
{
    cin>>el[i].x;
    el[i].id=i;
}
sort(el+1,el+n+1,cmp);
long long br=0;
for(i=1;i<=n;i++)
{
//cout<<el[i].x<<endl;
    if(el[i].x!=el[i-1].x){br++;el[i].w=br;}
    else
        el[i].w=br;
    first[el[i].id] = br;
}
//cout<<br<<endl;
calc(br,u);
//cout<<dp[br][u]<<endl;
long long k = dp[br][u]+1;
k/=2;
//cout<<k<<endl;
long long p,q,z,ost,ve;
for(i=0;i<=br+1;i++)
{
    pos[i].prev=0;
    pos[i].next=br+1;
    pos[i].st=-1;
}
pos[0].st=0;
pos[br+1].st=u+1;
long long delta=1;
int y;
for(i=1;i<=n;i++)
{
    delta=1;
    if(ansers[first[i]]!=0)continue;
    y = first[i];
    j=0;
    while(j!=br+1)
    {
        if(pos[j].next>y&&j<y)
        {
            p = y-j-1;
            q = pos[j].next-y-1;
            z = pos[pos[j].next].st - pos[j].st - 1;
            ost = pos[j].st;
            ve = j;
        }
        else
            delta= delta*(dp[pos[j].next-j-1][pos[pos[j].next].st-pos[j].st-1]);
        j = pos[j].next;
    }
   // cout<<p<<" "<<q<<" "<<z<<" "<<ost<<" "<<ve<<endl;
    for(j=1;j<=z;j++)
    {
       // cout<<j<<"::"<<delta<<" "<<dp[p][j-1]<<" "<<dp[q][z-j]<<endl;
        if(delta*dp[p][j-1]*dp[q][z-j]<k){k-=delta*dp[p][j-1]*dp[q][z-j];continue;}
       // cout<<y<<" "<<j+ost<<endl;
        ansers[y] = j+ost;
        pos[y].st = j+ost;
        pos[y].next = pos[ve].next;
        pos[pos[ve].next].prev = y;
        pos[y].prev=ve;
        pos[ve].next = y;
        break;
    }
}
for(i=1;i<=n;i++)
cout<<ansers[first[i]]<<" ";
cout<<endl;
    return 0;
}
/*
60 60
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
*/
