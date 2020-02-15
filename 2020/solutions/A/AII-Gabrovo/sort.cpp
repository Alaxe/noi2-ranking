# include<iostream>
using namespace std;

int a[100001];
long long ans=-1;
int n;
void solve(int i, int x, long long sum,int maxs)
{
    if(i>=n)
    {
        if(ans==-1 || ans>sum) ans=sum;
        return;
    }
    if(x<=a[i]) solve(i+1,a[i],sum,x);
    else
    {
        solve(i+1,x,sum+x-a[i],max(maxs,x));
        if(a[i]>=maxs) solve(i+1,a[i],sum+x-a[i],a[i]);
    }
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    solve(1,a[0],0,a[0]);

    cout<<ans<<endl;
}

/*
5
2 6 4 3 2
11
2 6 4 3 2 6 9 7 1 3 5
*/
