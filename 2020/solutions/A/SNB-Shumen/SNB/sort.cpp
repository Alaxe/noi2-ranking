#include<iostream>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;
int const maxn=100005;
int const inf=999999999;
int n;
int a[maxn];
int b[maxn];
stack<pair<int,int> >st;
int ans;

void sort_1()
{
    int i,tmax=b[0];
    pair<int,int>p;
    p.first=p.second=0;
    for(i=1;i<n;i++)
    {
        if(b[i]<=tmax)
        {
            b[i]=tmax;
            ans+=abs(a[i]-b[i]);
            p.second++;
        }
        else
        {
            tmax=b[i];
            st.push(p);
            p.first=p.second=i;
        }
    }
    st.push(p);
}

void solve()
{
    pair<int,int>p;
    bool blamp=false;
    while(!st.empty())
    {
        if(blamp==true)
            p.first=st.top().first;
        else p=st.top();
        st.pop();

        int tans=0,t=0;
        int i;
        bool lamp=0;

        for(i=p.first;i<=p.second;i++)
            tans+=abs(a[i]-b[i]);
        ans-=tans;

        blamp=false;
        while(1)
        {
            t=0;
            while(b[p.second]==a[p.second])
                p.second--;
            for(i=p.first;i<=p.second;i++)
            {
                b[i]--;
                if(b[i]==1)lamp=true;
                t+=abs(a[i]-b[i]);
            }

            if(t>=tans)
            {
                for(i=p.first;i<=p.second;i++)
                    b[i]++;
                break;
            }
            else
                tans=t;

            if(!st.empty()&&b[st.top().second]==b[p.first])
            {
                blamp=true;
                break;
            }
            if(lamp==true)break;

        }
        ans+=tans;
    }
}

int main()
{
    int i,mx=0,cnt=0,mx2=-1;
    bool l=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        mx=max(a[i],mx);
        if(mx>a[i])
        {
            if(mx2==-1)
                mx2=a[i];
            else
            {
                if(mx2>a[i])
                    l=true;
            }
            ans=max(mx-a[i],ans);
            cnt++;
        }

        b[i]=a[i];
    }

    if(cnt==1||l==0)
    {
        cout<<ans<<endl;
        return 0;
    }


    ans=0;
    sort_1();
    solve();

    cout<<ans<<endl;
    return 0;
}
/*

5
2 6 4 3 2

*/
