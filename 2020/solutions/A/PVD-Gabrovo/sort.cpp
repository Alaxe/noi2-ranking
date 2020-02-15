#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int32_t> a;

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	uint32_t n;
	cin>>n;
	a.resize(n);
	for(uint32_t i=0; i<n; i++)
		cin>>a[i];
}


//-----------------------------------------------------------------------------
static uint32_t solve_case_23_or_equal_helper (vector<int32_t> b, int32_t pos)
{
	if(!(1<=pos&&pos<=((int32_t)b.size())-2))
		return UINT32_MAX;

	int32_t res;

	if(b[pos-1]>b[pos+1])
		return UINT32_MAX;

	if(b[pos-1]<=b[pos]&&b[pos]<=b[pos+1])
		res=0;
	else
	{
		int32_t res2;
		res =b[pos-1]-b[pos];
		res2=b[pos+1]-b[pos];
		if(abs(res2)<abs(res))
		{
			res=res2;
		}
		b[pos]+=res;
		res=abs(res);
	}

	if(is_sorted(b.begin(), b.end()))
		return res;
	else
		return UINT32_MAX;
}

static void solve_case_23_or_equal (void)
{
	if(a.size()==1)
	{
		cout<<"0\n";
		exit(0);
	}

	vector<int32_t> b;
	b.reserve(a.size()+2);

	b.push_back(0);
	b.insert(b.end(), a.begin(), a.end());
	b.push_back(10100);

	for(uint32_t i=0; i<b.size()-1; i++)
	{
		if(b[i]>b[i+1])
		{
			int32_t cur_pos=(int32_t)i;
			uint32_t res=UINT32_MAX;

			uint32_t cur_res;
			for(int j=-2; j<=(+3); j++)
			{
				cur_res=solve_case_23_or_equal_helper(b, cur_pos+j);
				res=min(res, cur_res);
			}

			if(res!=UINT32_MAX)
			{
				cout<<res<<'\n';
				exit(0);
			}
			else
				return;
		}
	}

	cout<<"0\n";
	exit(0);

	asm volatile ("nop");
}
//-----------------------------------------------------------------------------

static inline uint32_t diff (uint32_t a, uint32_t b)
{
	int64_t ta=a, tb=b;
	int64_t res=ta-tb;
	return abs(res);
}

#define NMAX 1024
#define MMAX 10010

uint32_t dp[NMAX][MMAX];

void solve()
{
	for(uint32_t i=0; i<NMAX; i++)
	{
		for(uint32_t j=0; j<MMAX; j++)
		{
			dp[i][j]=UINT32_MAX;
		}
	}

	for(uint32_t i=0; i<MMAX; i++)
	{
		dp[0][i]=diff(a[0], i);
	}

//	for(uint32_t i=1; i<a.size(); i++)
//	{
//		for(uint32_t j=0; j<MMAX; j++)
//		{
//			for(uint32_t k=0; k<=j; k++)
//			{
//				dp[i][j]=min(dp[i][j], dp[i-1][k]+diff(a[i], j));
//			}
//		}
//	}

	for(uint32_t i=1; i<a.size(); i++)
	{
		uint32_t cur_min_pos=0, cur_min_val=dp[i-1][0];
		for(uint32_t j=0; j<MMAX; j++)
		{
//			for(uint32_t k=0; k<=j; k++)
//			{
//				dp[i][j]=min(dp[i][j], dp[i-1][k]+diff(a[i], j));
//			}

			if(cur_min_val>dp[i-1][j])
			{
				cur_min_val=dp[i-1][j];
				cur_min_pos=j;
			}

			dp[i][j]=min(dp[i][j], dp[i-1][cur_min_pos]+diff(a[i], j));
		}
	}

	uint32_t res=UINT32_MAX;

	for(uint32_t j=0; j<MMAX; j++)
	{
		res=min(res, dp[a.size()-1][j]);
	}

	cout<<res<<endl;
}

int main()
{
	init();

	if(a.size()>1000)
	{
		solve_case_23_or_equal();
	}
	else
	{
		solve();
	}


	return 0;
}
