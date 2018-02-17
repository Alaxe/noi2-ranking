#include<iostream>

using namespace std;

int a[1001],n,res=0;
bool b[1000001],boo[1000001][1001];

void solve(int sum,int pos,bool x)
{
    if(pos==n)
    {
        if(x==0)return;
        if(b[sum]==0)
        {
            res++;
            b[sum]=1;
        }
    }
    else
    {
        if(boo[sum][pos]==1)return;
        boo[sum][pos]=1;
        solve(sum,pos+1,x);
        solve(sum+a[pos],pos+1,1);
    }
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int i;
    
    cin>>n;
    
    for(i=0;i<n;i++)cin>>a[i];
    
    solve(0,0,0);
    
    cout<<res<<endl;
    
    return 0;
}