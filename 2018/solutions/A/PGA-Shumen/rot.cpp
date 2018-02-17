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
int b;
long long dl(long long x)
{
    long long br=0;
    while(x)
    {
        br++;
        x/=10;
    }
    return br;
}
vector<int> nm;
long long trans(long long l)
{
    long long i;
    long long res=0;
    for(i=0;i<l;i++)
    {
        res*=10;
        res+=1;
    }
    return res;
}
long long power(long long l)
{
    long long res=1;
    long long i=0;
    for(i=0;i<l;i++)
    {
        res*=b;
    }
    return res;
}
vector<int> base(long long x)
{
    vector<int> v;
    while(x)
    {
        v.push_back(x%b);
        x/=b;
    }
    return v;
}
int main()
{
	long long t;
	long long m;
	long long a;
	long long sz;
	int i;
	cin>>b;
	for(t=0;t<4;t++)
    {
        cin>>m;
        if(m%(b-1))
        {
            cout<<0<<endl;
            continue;
        }
        m/=(b-1);
        nm=base(m);
        sz=nm.size();
        //cout<<(power(sz)-1)/(b-1)<<endl;
        if(m+(power(sz)-1)/(b-1)>=power(sz))
        {
            sz++;
        }
        string ss="";
        ss+='1';
        vector<int> ans=base(m+(power(sz)-1)/(b-1));
        sz=ans.size();
        for(i=sz-1;i>=0;i--)
        {
            if(ans[i]>=10)
            {
                ss+='A'+ans[i]-10;
            }
            else
            {
                ss+='0'+ans[i];
            }
        }
        cout<<ss<<endl;
        //cout<<power(sz)+m+a<<endl;
    }
	return 0;
}
