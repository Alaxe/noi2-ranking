#include<bits/stdc++.h>
#include<cstdio>
#define MAXN 11005
using namespace std;
long long shir,vis,n,S[MAXN],z,t,p1,p2;
vector<long long> v[MAXN];
queue<long long> q;
struct masiv
{
    int x,y,x1,y1;
    long long S;
};
masiv arr[MAXN];
bool cmp(masiv a,masiv b)
{
    if(a.S!=b.S)return a.S<b.S;
    if(a.x!=b.x)return a.x<b.x;
    if(a.y!=b.y)return a.y<b.y;
    if(a.x1!=b.x1)return a.x1<b.x1;
    return a.y1<b.y1;
}
int main()
{

    scanf("%lld%lld%lld",&shir,&vis,&n);
    n++;
    arr[0].x=0;
    arr[0].y=0;
    arr[0].x1=shir;
    arr[0].y1=vis;
    arr[0].S=vis*shir;
    for(int i=1;i<n;i++)
    {

        scanf("%lld%lld%lld%lld",&arr[i].x,&arr[i].y,&z,&t);
        arr[i].S=z*t;
        arr[i].x1=arr[i].x+z;
        arr[i].y1=arr[i].y+t;
    }
    sort(arr,arr+n,cmp);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i].x>arr[j].x && arr[i].x1<arr[j].x1
               && arr[i].y>arr[j].y && arr[i].y1<arr[j].y1)
            {
                //cout<<i<<" "<<j<<endl;
                v[i].push_back(j);
                break;
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        if(v[i].size()!=0)arr[v[i][0]].S-=(arr[i].x1-arr[i].x)*(arr[i].y1-arr[i].y);
    }
    scanf("%lld",&t);
    for(int i=0;i<t;i++)

    {
        scanf("%lld%lld",&p1,&p2);
        //cin>>p1>>p2;
        for(int j=0;j<n;j++)
        {
            if(p1>=arr[j].x && p1<=arr[j].x1 && p2>=arr[j].y && p2<=arr[j].y1)
            {
                q.push(arr[j].S);
                break;
            }
        }
    }
    while(q.size()!=0)
    {
        printf("%lld\n",q.front());
        q.pop();
    }
    return 0;
}
/*
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3



13 10
6
1 1 6 8
9 7 1 2
3 7 2 1
2 2 4 4
3 3 2 2
9 3 3 3
4
4 4
6 8
10 5
10 2





*/
