#include<bits/stdc++.h>
using namespace std;
int AnswerProblem;
int n;
int a[1<<17];
int way1[1<<17];int c1[1<<19];
int way2[1<<17];int c2[1<<19];
void update1(int k,int left,int right,int pos,int x)
{
    if (left==right)
    {
        c1[k]=x;
        return ;
    }
    int middle=left+right;middle>>=1;
    if (pos<=middle)
    update1(k+k,left,middle,pos,x);
    else
    update1(k+k+1,middle+1,right,pos,x);
    c1[k]=max(c1[k+k],c1[k+k+1]);
}
void update2(int k,int left,int right,int pos,int x)
{
    if (left==right)
    {
        c2[k]=x;
        return ;
    }
    int middle=left+right;middle>>=1;
    if (pos<=middle)
    update2(k+k,left,middle,pos,x);
    else
    update2(k+k+1,middle+1,right,pos,x);
    c2[k]=max(c2[k+k],c2[k+k+1]);
}
int findmax1(int k,int left,int right,int x,int y)
{
    if (left>y||right<x)
    {
        return 0;
    }
    if (left>=x&&right<=y)
    {
        return c1[k];
    }
    int middle=left+right;middle>>=1;
    int ans1=findmax1(k+k,left,middle,x,y);
    int ans2=findmax1(k+k+1,middle+1,right,x,y);
    return max(ans1,ans2);
}
int findmax2(int k,int left,int right,int x,int y)
{
    if (left>y||right<x)
    {
        return 0;
    }
    if (left>=x&&right<=y)
    {
        return c2[k];
    }
    int middle=left+right;middle>>=1;
    int ans1=findmax2(k+k,left,middle,x,y);
    int ans2=findmax2(k+k+1,middle+1,right,x,y);
    return max(ans1,ans2);
}
void read(void)
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
}
void solve(void)
{
    update1(1,1,100000,a[1],1);
    update2(1,1,100000,a[1],1);
    for (int i=2;i<=n;i++)
    {
        int nowmax1=findmax1(1,1,100000,1,a[i]-1);
        //cout<<a[i]<<" "<<nowmax1<<endl;
        way1[a[i]]=nowmax1+1;
        update1(1,1,100000,a[i],way1[a[i]]);
        way2[a[i]]=max(way2[a[i]],way1[a[i]]);
        //update2(1,1,100000,a[i],way2[a[i]]);

        int nowmax2=findmax2(1,1,100000,a[i]+1,100000);

        way2[a[i]]=max(way2[a[i]],nowmax2+1);
        update2(1,1,100000,a[i],way2[a[i]]);
        AnswerProblem=max(AnswerProblem,way1[a[i]]);
        AnswerProblem=max(AnswerProblem,way2[a[i]]);
    }
}
void print(void)
{
    cout<<AnswerProblem<<endl;
}
int main()
{
    read();
    solve();
    print();
    return 0;
}
