#include<iostream>
#include<map>
#define MAX 100001
#define pow1 127
#define pow2 131
#define MOD1 1000000007
#define MOD2 1000000009
using namespace std;
int w,k;
int r1[MAX],r2[MAX];
int n,m;
int ans=0;
int ans2=0;
struct hash1
{
	long long h1,h2;
	void add(int d)
	{
        h1=(long long)(h1*pow1+d)%MOD1;
        h2=(long long)(h2*pow2+d)%MOD2;
	}
	void substract(int d, long long powF, long long powS)
	{
		///cout<<"sub "<<h1<<" "<<h2<<endl;
        h1=h1-(long long)d*powF;h1%=MOD1;if(h1<0)h1+=MOD1;
        h2=h2-(long long)d*powS;h2%=MOD2;if(h2<0)h2+=MOD2;
		///cout<<"sub2 "<<h1<<" "<<h2<<endl;
	}
	bool operator == (const hash1 &i) const
	{
		if(h1==i.h1 && h2==i.h2)
			return true;
		return false;
	}
	bool operator < (const hash1 &i) const
	{
		return h1<i.h1;
	}
};
map <hash1, int> mr1;
map <int, int> mr2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>w>>k;
	cin>>n;
	hash1 h;
	cin>>r1[0];
	h.h1=r1[0];
	h.h2=r1[0];
	int cnt=1, cnt1=1;
	long long p1=1,p2=1;

	for(int a=1; a<k; a++)
	{
		p1*=pow1;p1%=MOD1;
		p2*=pow2;p2%=MOD2;
	}

	for(int a=1; a<n; a++)
	{
		cin>>r1[a];
		if(cnt==k)
		{
            if(mr1.find(h)!=mr1.end())
			{
                mr1[h]++;
			}
			else mr1[h]=1;
            h.substract(r1[a-k],p1,p2);
            cnt--;
		}
		if(r1[a]>r1[a-1])
		{
			cnt++;
            h.add(r1[a]);
		}
		else
		{
			h.h1=r1[a];
			h.h2=r1[a];
			cnt=1;
		}

		if(r1[a]==r1[a-1])
		{
			cnt1++;
		}
		else
			cnt1=1;
		if(cnt1==k)
		{
			///cout<<r1[a]<<endl;
			if(mr2.find(r1[a])==mr2.end())
			{
				mr2[r1[a]]=1;
			}
			else mr2[r1[a]]++;
			cnt1--;
		}

	}


	if(cnt==k)
	{
		if(mr1.find(h)!=mr1.end())
		{
			mr1[h]++;
		}
		else mr1[h]=1;
	}
	cnt=1;
	cnt1=1;
	cin>>m;
	cin>>r2[0];
	h.h1=r2[0];
	h.h2=r2[0];
	for(int a=1; a<m; a++)
	{
		cin>>r2[a];
		if(cnt==k)
		{
            if(mr1.find(h)!=mr1.end())
			{
				ans+=mr1[h];
			}
			h.substract(r2[a-k],p1,p2);
			cnt--;
		}
		if(r2[a]>r2[a-1])
		{
			cnt++;
            h.add(r2[a]);
		}
		else
		{
			h.h1=r2[a];
			h.h2=r2[a];
			cnt=1;
		}

        if(r2[a]==r2[a-1])
		{
			cnt1++;
		}
		else cnt1=1;
        if(cnt1==k)
		{

			if(mr2.find(r2[a])!=mr2.end())
			{
				ans2+=mr2[r2[a]];
			}
			cnt1--;
		}
	}
	if(cnt==k)
	{
		if(mr1.find(h)!=mr1.end())
		{
			ans+=mr1[h];
		}
	}
	if(w==1)
		cout<<ans<<endl;
	if(w==2)
		cout<<ans2<<endl;
	return 0;
}
/**
1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7


2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6

1 5
12
110 130 170 190 200 210 80 110 130 170 190 200
16
80 110 130 170 190 50 80 70 1030 80 110 130 170 190 200 210

2 7
18
181 181 181 181 181 181 181 181 181 181 181 181 181 181 181 181 181 181
14
181 181 181 181 181 181 181 181 181 181 181 181 181 181
*/
