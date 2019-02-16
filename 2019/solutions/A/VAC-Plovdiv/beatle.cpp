#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+17;

int n, m;
struct node
{
	int mx, lazy;
	node() {mx=MAXN; lazy=0;}
	node(int val) {mx=val; lazy=0;}
};
node temp, broken;
node merge(node l, node r) {temp.mx=min(l.mx, r.mx); temp.lazy=0; return temp;}

struct segment_tree
{
	node tr[4*MAXN];
	void push(int l, int r, int idx)
	{
		if(tr[idx].lazy)
		{
			tr[idx].mx=tr[idx].lazy;
			if(l!=r) tr[2*idx+1].lazy=tr[idx].lazy, tr[2*idx+2].lazy=tr[idx].lazy;
			tr[idx].lazy=0;
		}
	}

	void init(int l, int r, int idx)
	{
		if(l==r) {tr[idx]=node(n+1); return;}

		int mid=(l+r)>>1;
		init(l, mid, 2*idx+1);
		init(mid+1, r, 2*idx+2);
		tr[idx]=merge(tr[2*idx+1], tr[2*idx+2]);
	}

	void update(int qL, int qR, int val, int l, int r, int idx)
	{
		push(l, r, idx);
		if(qL>r||l>qR||l>r||qL>qR) return;

		if(qL<=l&&r<=qR)
		{
			tr[idx].lazy=val;
			push(l, r, idx);
			return;
		}

		int mid=(l+r)>>1;
		update(qL, qR, val, l, mid, 2*idx+1);
		update(qL, qR, val, mid+1, r, 2*idx+2);
		tr[idx]=merge(tr[2*idx+1], tr[2*idx+2]);
	}

	node query(int pos, int l, int r, int idx)
	{
		push(l, r, idx);
		if(l>pos||r<pos) return broken;
		if(l==pos&&r==pos) return tr[idx];

		int mid=(l+r)>>1;
		return merge(query(pos, l, mid, 2*idx+1), query(pos, mid+1, r, 2*idx+2));
	}
};

vector<int> G[MAXN]; //id
vector<int> ys; //compressed y
struct edge {int x1, x2, id;};
vector<edge> Gall[MAXN]; //all
int dist[MAXN];

segment_tree trr;
void mainp()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x, y, d;
        cin>>x>>y>>d;
        Gall[y].push_back({x, x+d, i});
        ys.push_back(y);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    trr.init(0, MAXN-1, 0);
    broken.mx=MAXN;
    broken.lazy=0;

    for(int i=0; i<ys.size(); i++)
        for(int j=0; j<Gall[ys[i]].size(); j++)
        {
            edge tp=Gall[ys[i]][j];
            node l=trr.query(tp.x1-1, 0, MAXN-1, 0);
            node r=trr.query(tp.x2, 0, MAXN-1, 0);

            G[tp.id].push_back(r.mx);
            if(r.mx!=l.mx) G[tp.id].push_back(l.mx);
            trr.update(tp.x1, tp.x2-1, tp.id, 0, MAXN-1, 0);
        }

    dist[n+1]=0;
    for(int i=0; i<ys.size(); i++)
        for(int j=0; j<Gall[ys[i]].size(); j++)
        {
            edge tp=Gall[ys[i]][j];
            dist[tp.id]=MAXN;
            for(int k=0; k<G[tp.id].size(); k++) dist[tp.id]=min(dist[tp.id], dist[G[tp.id][k]]+1);
        }

    vector<int> t;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int tp;
        cin>>tp;
        node l=trr.query(tp, 0, MAXN-1, 0);
        t.push_back(dist[l.mx]);
    }

    for(int i=0; i<t.size(); i++) cout<<t[i]<<" ";
    cout<<endl;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    mainp();
    return 0;
}

/*

13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11

*/
