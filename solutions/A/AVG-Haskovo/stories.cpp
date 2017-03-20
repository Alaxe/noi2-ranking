#include<iostream>
#include<stack>
using namespace std;
int a[10000009];
struct st
{
    int x,y,z;
};
stack <st> s;
int main()
{
    int n,k;
    cin>>n>>k;
    long long int fir,mul,ad,md,x,y,ans=0;
    cin>>fir>>mul>>ad>>md;
    x=fir;
    a[1]=x;
    for(int i=2;i<=n;i++)
    {
        x=(x*mul+ad)%md;
        a[i]=x;
    }
    st q,e;
    q.x=a[n];
    q.y=n;
    q.z=1;
    s.push(q);
    for(int i=n-1;i>=1;i--)
    {
        q.x=a[i];
        q.y=i;
        q.z=1;
        while(!s.empty())
        {
           // cout<<i<<endl;
            e=s.top();
            x=e.y-q.y;
            if(x>=k)break;
            if(e.x>=q.x)break;
            else
            {
                if(x+e.z<=k){q.z=x+e.z;s.pop();}
                else
                {
                    y=k-x;
                    e.z-=y;
                    q.z+=y;
                    s.pop();
                    s.push(e);
                    break;
                }
            }
        }
        s.push(q);
    }
    while(!s.empty())
    {
        x=s.top().x;
        y=s.top().z;
        ans+=x*y;
        s.pop();
    }
    cout<<ans<<endl;
    return 0;
}
/*

1000000 84
1000000001
1000000002
1000000003
1000000007


10000000 84
1000000001
1000000002
1000000003
1000000007
*/
