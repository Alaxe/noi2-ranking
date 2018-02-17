#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;
long long dp[64][70];
int z;
long long s,t;
int check(long long x)
{
    int br=0;
    while(x)
    {
        if(x%2==0) br++;
        x/=2;
    }
    return br;
}
long long rev(vector<int> v)
{
    int i;
    long long num=0;
    int sz=v.size();
    for(i=0;i<sz;i++)
    {
        num=2*num+v[i];
    }
    return num;
}
/*long long case1(long long x, int br)
{
    vector<int> dv=dvo(x);
    int i=0;
    int sz=dv.size();
    int res=br-z;
    for(i=sz-1;res>0;i--)
    {
        if(v[i]==0)
        {
            v[i]=1;
            res--;
        }
    }
    return rev(dv);
}
long long case2(long long x)
{
    vector<int> dv=dvo(x);
    int i,sz=dv.size();
    for(i=1;i<sz;i++)
    {
        if(v[i]==0)
        {

        }
    }
}*/
int lg(long long x)
{
    int br=0;
    while(x)
    {
        br++;
        x/=2;
    }
    return br;
}
void init()
{
    int i,j;
    for(i=0;i<70;i++)
    {
        dp[0][i]=1;
    }
    for(i=1;i<=z;i++)
    {
        for(j=i;j<70;j++)
        {
            dp[i][j]=dp[i-1][j]*(j-i+1)/(i);
        }
    }
}
int lgs,lgt;
vector<int> dvo(long long x)
{
    vector<int> v;
    stack<int> st;
    while(x)
    {
        st.push(x%2);
        x/=2;
    }
    while(!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    return v;
}
int main()
{
	cin>>s>>t>>z;
	int i,j;
	/*int fans=0;
	for(i=s;i<=t;i++)
    {
        if(check(i)==z)
        {
            fans++;
        }
    }*/
	init();
	lgs=lg(s);
	lgt=lg(t);
	if(lgt-1<z)
    {
        cout<<0<<endl;
        return 0;
    }
	long long ans=0;
	for(i=z;i<=lgt-2;i++)
    {
        ans+=dp[z][i];
    }
    for(i=z;i<=lgs-2;i++)
    {
        ans-=dp[z][i];
    }
	long long num;
	/*for(num=s;;num++)
    {
        if(check(num))
        {
            if(s!=num) ans++;
            s=num;
            break;
        }
    }
	for(num=t;;num++)
    {
        if(check(num))
        {
            if(t!=num) ans--;
            t=num;
            break;
        }
    }*/
    vector<int> dvs=dvo(s);
    vector<int> dvt=dvo(t);
    long long sum=0;
    int sz=dvs.size();
    num=z-1;
    for(i=1;i<sz;i++)
    {
        if(dvs[i]==0)
        {
            num--;
        }
        else
        {
            sum+=dp[num][sz-i-1];
        }
    }
    ans-=sum;
    sum=0;
    sz=dvt.size();
    num=z-1;
    for(i=1;i<sz;i++)
    {
        if(dvt[i]==0)
        {
            num--;
        }
        else
        {
            sum+=dp[num][sz-i-1];
        }
    }
    if(check(t)==z) ans++;
    ans+=sum;
    /*if(ans==fans)
    {
        cout<<"ok"<<endl;
    }
    else
    {
        cout<<"много шибаничко"<<endl;
    }*/
    cout<<ans<<endl;
	return 0;
}
