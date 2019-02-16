#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n;
struct line
{
    int x,y,d;
};
line inp[nmax];
bool cmp(line a,line b)
{
    return a.y<b.y;
}
int tree[4*nmax];
int query(int node,int l,int r,int pos)
{
    if(tree[node]||l==r)return tree[node];
    int av=(l+r)/2;
    if(pos<=av)return query(node*2,l,av,pos);
    return query(node*2+1,av+1,r,pos);
}
void update(int node,int l,int r,int lq,int rq,int value)
{
    if(l==lq&&r==rq)
    {
        tree[node]=value;
        return;
    }
    if(tree[node])
    {
    tree[node*2]=tree[node];
    tree[node*2+1]=tree[node];
    tree[node]=0;
    }
    int av=(l+r)/2;
    if(lq<=av)update(node*2,l,av,lq,min(av,rq),value);
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,value);
}
int x[nmax],ans[nmax];
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
{
    scanf("%i%i%i",&inp[i].x,&inp[i].y,&inp[i].d);
}
sort(inp+1,inp+n+1,cmp);
for(int i=1;i<=n;i++)
{
    int val=1+min(query(1,0,nmax,inp[i].x-1),query(1,0,nmax,inp[i].x+inp[i].d));
    update(1,0,nmax,inp[i].x,inp[i].x+inp[i].d-1,val);
    /*
    cout<<inp[i].x<<" "<<inp[i].d<<" was added"<<endl;
    for(int j=0;j<14;j++)
        cout<<query(1,0,nmax,j)<<" ";cout<<endl;
    */

}


int t;
scanf("%i",&t);
for(int i=1;i<=t;i++)
{
    scanf("%i",&x[i]);
    ans[i]=query(1,0,nmax,x[i]);
}
printf("%i",ans[1]);
for(int i=2;i<=t;i++)printf(" %i",ans[i]);
printf("\n");
return 0;
}
/*
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11
*/
