#include<iostream>
using namespace std;
long long w,h,sum=0;
int n,a[150050];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>w>>h;
    cin>>n;
    long long x1,x,y1,y;
    cin>>x1>>y1;
    for(int i=2;i<=n;i++)
    {
        cin>>x>>y;
        if(x==x1)
        {
            int f=0;
            if(y<y1)
            {
                swap(y,y1);
                f=1;
            }
            for(int j=y1;j<y;j++)
            {
                if(x>a[j]) a[j]=x;
            }
            if(f==1) swap(y1,y);
        }
        x1=x;y1=y;
    }
    cout<<endl;
    for(int i=0;i<h;i++)
    {
        cout<<a[i]<<endl;
        sum+=a[i];
    }
    cout<<endl;
    long long ans;
    ans=h*w-sum;
    cout<<ans<<endl;
    return 0;
}
