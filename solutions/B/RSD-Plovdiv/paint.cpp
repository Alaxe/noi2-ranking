#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
const int MAXN = (1 << 15);
const int MAXB = (1 << 14);
const int bound = 12042;
/*1
template <class T>
struct fenwick
{
	int sz;
	vector<T> tr;

	void init(int n)
	{
		sz = n + 1;
		tr.assign(sz + 2, 0);
	}

	T query(int idx)
	{
		T ans = 0;
		for(; idx >= 1; idx -= (idx & -idx))
			ans += tr[idx];
		return ans;
	}

	void update(int idx, T val)
	{
		if(idx <= 0) return;
		for(; idx <= sz; idx += (idx & -idx))
			tr[idx] += val;
	}

	T query(int l, int r) { return query(r) - query(l - 1); }
};

template<class T>
struct compressed_fenwick
{
	fenwick<T> t;
	vector<int> li;

	int get_idx(int x) { return lower_bound(li.begin(), li.end(), x) - li.begin() + 1; }
	void update(int x, T val) { t.update(get_idx(x), val); }

	void add_to_prep(int x) { li.push_back(x); }
	void prepare() 
	{ 
		sort(li.begin(), li.end());
		li.erase(unique(li.begin(), li.end()), li.end());
		t.init(li.size() + 2); 
	}

	T query(int x) { return t.query(get_idx(x) - 1); }
    T size() { return t.query(t.sz); }
};

struct segment_tree
{
	compressed_fenwick<long long> tr[4 * MAXB];

	void init(int l, int r, int idx)
	{
		if(l == r)
		{
			tr[idx].prepare();
			return;
		}

		int mid = (l + r) >> 1;
		init(l, mid, 2 * idx + 1);
		init(mid + 1, r, 2 * idx + 2);

		tr[idx].prepare();
	}

	void update(int pos, int val, long long P, int l, int r, int idx)
	{
		if(l > pos || r < pos)
			return;

		if(l == r && l == pos)
		{
			tr[idx].update(val, P);
			return;
		}

		int mid = (l + r) >> 1;
		update(pos, val, P, l, mid, 2 * idx + 1);
		update(pos, val, P, mid + 1, r, 2 * idx + 2);

		tr[idx].update(val, P);
	}

	void add(int pos, int val, int l, int r, int idx)
	{
		if(l > pos || r < pos)
			return;

		if(l == r && l == pos)
		{
			tr[idx].add_to_prep(val);
			return;
		}

		int mid = (l + r) >> 1;
		add(pos, val, l, mid, 2 * idx + 1);
		add(pos, val, mid + 1, r, 2 * idx + 2);

		tr[idx].add_to_prep(val);
	}

	long long query(int qL, int qR, int k, int l, int r, int idx)
	{
		if(qL > qR) return 0;
		if(l > qR || r < qL)
			return 0;

		if(qL <= l && r <= qR)
			return tr[idx].query(k);

		int mid = (l + r) >> 1;
		return query(qL, qR, k, l, mid, 2 * idx + 1) + query(qL, qR, k, mid + 1, r, 2 * idx + 2);
	}
};
*/

int n, w, h;
pair<int, int> p[MAXN];
pair<long long, int> pidx[MAXN];
int dx[MAXN], dy[MAXN];
long long answer[MAXN];

void read()
{
	scanf("%d%d", &w, &h);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int wp, hp;
		scanf("%d%d%d%d", &p[i].first, &p[i].second, &wp, &hp);
		long long area = wp * 1ll * hp;
		pidx[i] = make_pair(area, i);
		dx[i] = p[i].first + wp;		
		dy[i] = p[i].second + hp;
	}
}

//segment_tree t;

bool is_inside(int px, int py, int i) { return p[i].first < px && px < dx[i] && p[i].second < py && py < dy[i]; }

int get_rect(int px, int py)
{
	for(int i = 0; i < n; i++)
		if(is_inside(px, py, pidx[i].second))
			return pidx[i].second;	
	return n;
}

void solve()
{
	/*for(int i = 0; i < n; i++)
		t.add(p[i].first, p[i].second, 0, bound, 0);
	t.init(0, bound, 0);

	sort(pidx, pidx + n);
	for(int pos_pidx = 0; pos_pidx < n; pos_pidx++)
	{
		int i = pidx[pos_pidx].second;
		answer[i] = pidx[pos_pidx].first - t.query(p[i].first, dx[i], dy[i], 0, bound, 0); 
		answer[i] =  answer[i] + t.query(p[i].first, dx[i], p[i].second, 0, bound, 0);
		t.update(p[i].first, p[i].second, answer[i], 0, bound, 0);
	}
	

	answer[n] = w * h - t.query(0, w, h, 0, bound, 0);
	*/

	long long sum = 0;
	int i;
	sort(pidx, pidx + n);
	for(int po = 0; po < n; po++)
	{
		i = pidx[po].second;
		answer[i] = pidx[po].first;
		for(int j = 0; j < po; j++)
			if(is_inside(p[pidx[j].second].first, p[pidx[j].second].second, i))
				answer[i] -= answer[pidx[j].second];
		sum += answer[i];
	}

	answer[n] = w * h - sum;

	int q;
	scanf("%d", &q);
	for(int te = 0; te < q; te++)
	{
		int px, py;
		scanf("%d%d", &px, &py);
		printf("%lld\n", answer[get_rect(px, py)]);
	}
}

int main()
{
	read();
	solve();
	return 0;
}
