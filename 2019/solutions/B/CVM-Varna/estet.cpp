#include<bits/stdc++.h>
#define N 100001
using namespace std;
int m[N],a[N],lis[N],lds[N];
int main()
{
    //freopen("input1.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>m[i];
    int maxlis=1; int sz=1; a[0]=m[0];
    lis[0]=1;
    for(int i=1;i<n;i++)
    {
        if(m[i]>a[sz-1]){a[sz++]=m[i]; lis[i]=sz;}
        else
        {
            int l=0,r=sz-1,ans=0;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(m[i]==a[mid]){ans=mid; break;}
                else if(m[i]>a[mid]) l=mid+1;
                else{ans=mid; r=mid-1;}
            }
            a[ans]=m[i];
            lis[i]=ans+1;
        }
    }
    memset(a,0,sizeof(a));
    lds[n-1]=1; sz=1; a[0]=m[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(m[i]>a[sz-1]){a[sz++]=m[i]; lds[i]=sz;}
        else
        {
            int l=0,r=sz-1,ans=0;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(m[i]==a[mid]){ans=mid; break;}
                else if(m[i]>a[mid]) l=mid+1;
                else{ans=mid; r=mid-1;}
            }
            a[ans]=m[i];
            lds[i]=ans+1;
        }
    }
    int maxres=0;
    for(int i=0;i<n;i++) maxres=max(maxres,lis[i]+lds[i]-1);
    cout<<maxres<<endl;
    return 0;
}
/**

12
2 8 6 3 5 1 6 9 6 5 2 7

*/
