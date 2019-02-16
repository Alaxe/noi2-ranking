#include<bits/stdc++.h>
using namespace std;
int n, up[100002], down[100002], act[100002];
void upper()
{
    int wrk[100002], ind=0;
    memset(wrk, 0, sizeof(wrk));
    //for(int i=0;i<n;i++)cout<<wrk[i];
    up[0]=1;
    wrk[0]=act[0];
    for(int i=1; i<n; i++)
    {
        bool f=false;
        for(int j=ind; j>=0; j--)
        {
            if(wrk[j]<act[i])
            {
                if(wrk[j+1]==0)ind++;
                wrk[j+1]=act[i];
                f=true;
                break;
            }
        }
        if(!f)wrk[0]=act[i];
        up[i]=ind+1;
    }
}
void lower()
{
    int wrk[100002], ind=0;
    memset(wrk, 0, sizeof(wrk));
    down[n-1]=1;
    wrk[0]=act[n-1];
    for(int i=n-2; i>=0; i--)
    {
        bool f=false;
        for(int j=ind; j>=0; j--)
        {
            if(wrk[j]<act[i])
            {
                if(wrk[j+1]==0)ind++;
                wrk[j+1]=act[i];
                f=true;
                break;
            }
        }
        if(!f)wrk[0]=act[i];
        down[i]=ind+1;
    }
}
int main()
{
    cin>>n>>act[0];
    for(int i=1; i<n; i++)
    {
        cin>>act[i];
        if(act[i]==act[i-1])
        {
            i--;
            n--;
        }
    }
    upper();
    lower();
    //cout<<up[n-1]<<" "<<down[0]<<"\n";
    int ans=max(up[n-1], down[0]);
    for(int i=0;i<n-1;i++)if(ans<up[i]+down[i+1])ans=up[i]+down[i+1];
    cout<<ans<<"\n";
    //for(int i=0;i<n;i++)cout<<down[i]<<"\n";
    return 0;
}
/*
9
2 4 5 3 4 5 1 3 2
*/
