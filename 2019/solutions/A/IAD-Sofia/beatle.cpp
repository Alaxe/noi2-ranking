#include <iostream>
#include <algorithm>

//#pragma GCC optimize "Ofast"
//#pragma GCC target "sse4.1"

using namespace std;

struct line
{
	int x, y;
	int l;
	int ls, rs;
	bool ll, rr;
}inp[160002];

bool operator<(line a, line b)
{
    if(a.y > b.y) return 1;
    if(a.y < b.y) return 0;
    if(a.x > b.x) return 0;
    if(a.x < b.x) return 1;
    return a.l < b.l;
}
int task[60001];
int first[160002];
int ann[160002];
int n, t;
int ans(int curr, bool f)
{
    if(curr == 0 && !f) return 0;
	//cout << "On " << curr << endl;
    if(ann[curr]) return ann[curr];
    //cout << "Falling to " << inp[curr].ls << endl;
    while(inp[curr].ls != 0 && inp[curr].x == inp[inp[curr].ls].x) inp[curr].ls = inp[inp[curr].ls].ls;
    if(inp[curr].l > 0) while(inp[curr].rs != 0 && inp[curr].x+inp[curr].l == inp[inp[curr].rs].x+inp[inp[curr].rs].l) inp[curr].rs = inp[inp[curr].rs].rs;
    int la = ans(inp[curr].ls, 0);
    //cout << "Falling to " << inp[curr].rs << endl;
    int ra = ans(inp[curr].rs, 0);
    if(la < ra)
	{
		if(inp[curr].ls != 0) la ++;
		ann[curr] = la;
		return la;
	}
	if(la > ra)
	{
		if(inp[curr].rs != 0) ra ++;
		ann[curr] = ra;
		return ra;
	}
	if(inp[curr].ls != 0 && inp[curr].rs != 0) la ++;
	ann[curr] = la;
	return la;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int mx = 0, my = 0;
	for(int i = 0; i < n; i ++)
	{
        cin >> inp[i].x >> inp[i].y >> inp[i].l;
        mx = max(inp[i].x+inp[i].l, mx);
        my = max(inp[i].y, my);
	}
	cin >> t;
	for(int i = 0; i < t; i ++)
	{
        cin >> task[i];
        inp[n+i].x = task[i]+1;
        inp[n+i].y = my+1;
        inp[n+i].l = 0;
        mx = max(task[i]+2, mx);
	}
	for(int i = 0; i <= mx; i ++) first[i] = -1;
    sort(inp, inp+n+t);
    //cout << endl << inp[6].l << endl;
    for(int i = 0; i < n+t; i ++)
	{
		//cout << "Na liniq " << i << endl;
        for(int ax = inp[i].x; ax <= inp[i].x+inp[i].l; ax ++)
		{
			//cout << "V x " << ax << endl;
            if(first[ax] > -1)
			{
				line a = inp[first[ax]];
				line b = inp[i];
                if(a.x+a.l <= b.x+b.l && inp[first[ax]].rs == 0)
				{
					//cout << "Otdqsno na " << first[ax] << endl;
                    inp[first[ax]].rs = i;
				}
				if(a.x+a.l == b.x+b.l && inp[first[ax]].rs == 0)
				{
                    inp[first[ax]].rr = 1;
				}
				if(a.x >= b.x && inp[first[ax]].ls == 0)
				{
					//cout << "Otlqvo na " << first[ax] << endl;
                    inp[first[ax]].ls = i;
				}
				if(a.x == b.x && inp[first[ax]].ls == 0)
				{
                    inp[first[ax]].ll = 1;
				}
			}
			first[ax] = i;
		}
		//cout << endl << endl;
		//napravi ako leviq ili desniq krai e zaet proverka ot koq strana
	}
	/*for(int i = 0; i < n+t; i ++)
	{
		cout << inp[i].ls << " " << inp[i].rs << " " << i << endl;
	}*/
    for(int i = 0; i < t; i ++)
	{
        cout << ans(i, 1) << " ";
	}
	cout << endl;
}
