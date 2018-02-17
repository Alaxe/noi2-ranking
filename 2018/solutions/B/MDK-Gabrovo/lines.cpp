#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42;
struct p
{
int x,y;
};
int n;
p inp[nmax];
int nod(int a,int b)
{
int m=1;
if(b<0)m=-1;
a=abs(a);
b=abs(b);
if(b==0)return m*a;
if(a==0)return m*b;
int r=a%b;
while(r)
{
a=b;
b=r;
r=a%b;
}
return m*b;
}
pair<int,int> now[nmax];
bool cmp(pair<int,int>a,pair<int,int>b)
{
return a.first*b.second<a.second*b.first;
}
int eval()
{
sort(now+1,now+n,cmp);
int t=0;
for(int i=1;i<n;i++)
{
int j=i;
while(j<n&&now[i]==now[j])j++;
t=max(t,j-i);
i=j-1;
}
return t;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>inp[i].x>>inp[i].y;

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int pos=0;
        for(int j=1;j<=n;j++)
        if(i!=j)
        {
        int xd=inp[i].x-inp[j].x,yd=inp[i].y-inp[j].y;
        int G=nod(xd,yd);
        xd=xd/G;
        yd=yd/G;
        //cout<<"xd= "<<xd<<" yd= "<<yd<<endl;
        pos++;
        now[pos]=make_pair(xd,yd);
        }
    ans=max(ans,eval());
    }
    //cout<<ans<<endl;
    cout<<ans+1<<endl;
    return 0;
}
/*
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
*/
