#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
const int MAXN = (1 << 18);
const long long inf = 10000000000000ll;

struct node
{
	long long mx, lazy;
	node() { mx = -inf; lazy = -inf; }
	node(long long _mx) { mx = _mx; lazy = -inf; }
};

node temp, broken;

node merge(node l, node r)
{
	temp.mx = max(l.mx, r.mx);
	temp.lazy = -inf;
	return temp;
}

struct segment_tree
{
	node tr[4 * MAXN];

	void push(int l, int r, int idx)
	{
		if(tr[idx].lazy != -inf)
		{
			tr[idx].mx = max(tr[idx].mx, tr[idx].lazy);

			if(l != r)
			{
				tr[2 * idx + 1].lazy = max(tr[2 * idx + 1].lazy, tr[idx].lazy);
				tr[2 * idx + 2].lazy = max(tr[2 * idx + 2].lazy, tr[idx].lazy);
			}
		
			tr[idx].lazy = -inf;
		}
	}

	void init(int l, int r, int idx)
	{
		if(l == r) { tr[idx] = node(0); return; }

		int mid = (l + r) >> 1;	
		init(l, mid, 2 * idx + 1);
		init(l, mid, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}
	
	void update(int qL, int qR, long long val, int l, int r, int idx)
	{
		push(l, r, idx);
		if(l > qR || r < qL)
			return;

		if(qL <= l && r <= qR) 
		{ 
			tr[idx].lazy = val;
			push(l, r, idx);
			return; 
		}

		int mid = (l + r) >> 1;	
		update(qL, qR, val, l, mid, 2 * idx + 1);
		update(qL, qR, val, mid + 1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}

	node query(int qL, int qR, int l, int r, int idx)
	{
		push(l, r, idx);
		if(l > qR || r < qL)
			return broken;
		
		if(qL <= l && r <= qR)
			return tr[idx];

		int mid = (l + r) >> 1;
		return merge(query(qL, qR, l, mid, 2 * idx + 1), query(qL, qR, mid + 1, r, 2 * idx + 2));
	}
};

long long w, h;
pair<long long, long long> p[MAXN];
int n;

void read()
{
	scanf("%lld %lld", &w, &h);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld %lld", &p[i].first, &p[i].second);
}

vector<long long> comp;
int get_idx(long long x) { return lower_bound(comp.begin(), comp.end(), x) - comp.begin(); }

segment_tree t;

void solve()
{
	for(int i = 0; i < n; i++)
		comp.push_back(p[i].second);

	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	t.init(0, comp.size() + 1, 0);

	for(int i = 1; i < n; i++)
	{
		if(p[i].second == p[i - 1].second) continue;
		long long L = p[i].second, R = p[i - 1].second;
		if(L > R) swap(L, R);
		t.update(get_idx(L) + 1, get_idx(R), p[i].first, 0, comp.size() + 1, 0);
	}

	long long ans = 0;
	for(int i = 1; i < comp.size(); i++)
		ans += (comp[i] - comp[i - 1]) * 1ll * (w - t.query(i, i, 0, comp.size() + 1, 0).mx);

	printf("%lld\n", ans);
}

int main()
{
	read();
	solve();
	return 0;
}

