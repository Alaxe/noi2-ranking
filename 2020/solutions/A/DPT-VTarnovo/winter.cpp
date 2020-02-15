#include <bits/stdc++.h>

using namespace std;

#define MAX 300000

vector<int> gr[MAX];

long long n, m, a, b, idx[MAX], d[MAX], l[MAX], no = -1, br[MAX], tk;

bool ap[MAX];

long long ans;

bool used[MAX];

set<int> s[MAX];

void dfs(int v, int t, int par)
{
	int child = 0;
	used[v] = 1;
	d[v] = l[v] = ++t;
	for(int i = 0; i < gr[v].size(); i++)
	{
		if(used[gr[v][i]] == 0)
		{
			child++;
			dfs(gr[v][i], t + 1, v);
			l[v] = min(l[v], l[gr[v][i]]);
			if(l[gr[v][i]] >= d[gr[v][i]])
			{
				s[v].insert(gr[v][i]);
				s[gr[v][i]].insert(v);
			}
		}
		else if(par != gr[v][i])l[v] = min(l[v], d[gr[v][i]]);
		if(gr[gr[v][i]].size() < 2)
		{
			s[v].insert(gr[v][i]);
			s[gr[v][i]].insert(v);
		}
	}
}

int dfk(int v, bool tr)
{
	br[v] = 1;
	used[v] = 1;
	for(int i = 0; i < gr[v].size(); i++)
	{
		if(used[gr[v][i]] == 0)
		{
			if(s[v].count(gr[v][i]) == 1)
			{
				//cout << v << " " << gr[v][i] << endl;
				dfk(gr[v][i], 1);
			}
			else
			{
				//cout << v << " " << gr[v][i] << endl;
				dfk(gr[v][i], 0);
				br[v] += br[gr[v][i]];
			} 
		}
	}
	
	if(tr == 1)
	{
		tk = br[v];
		tk *= (br[v] - 1);
		tk /= 2;
		ans += tk;
	}
	return br[v];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d",&a,&b);
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(1, 1, -1);
	fill(used, used + n + 3, 0);
	dfk(1, 1);
	printf("%lld\n", ans);
	return 0;
}

/*

5 6
1 2
1 3
2 3
1 4
4 5
5 2

11 14
1 2
1 3
2 4
3 4
4 5
5 6
6 11
5 7
7 8
8 10
8 9
7 9
9 10
3 8
-----------------
36

13 16
5 6
5 7
6 7
2 5
1 3 
1 2
2 3
3 4
4 8
4 9
8 11
9 10
10 11
9 12
9 13
12 13
------------------
27

7 6
1 2 
1 3
1 4
4 5
1 6
1 7


*/
