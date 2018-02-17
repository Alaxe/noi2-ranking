#include<bits/stdc++.h>
#define double long double
#define endl '\n'
const int MAXN=(1<<20);
const double dinf=(double)1e17;
const double eps=1e-9;
using namespace std;
struct point
{
    int x, y;
    point() {x=0; y=0;}
    point(int _x, int _y) {x=_x; y=_y;}
};

double slope(point a, point b)
{
	double deltax=b.x-a.x;
	double deltay=b.y-a.y;
	if(max(-deltax, deltax)<eps) return dinf;

	return deltay/deltax;
}

point I;
bool cmp(point a, point b)
{
    return slope(a, I)<slope(b, I);
}

vector<point> p, pp;
void mainp()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        p.push_back(point(a, b));
    }
    if(n<=2) {cout<<n<<endl; return;}

    int ans=0;
    for(int i=0; i<n; i++)
    {
        I=p[i];
        pp.clear();
        int add = 0;
        for(int j = 0; j < n; j++) {if(p[j].x == p[i].x && p[j].y == p[i].y) add++; else pp.push_back(p[j]);}
        sort(pp.begin(), pp.end(), cmp);

        if(pp.size()==0) {ans=max(ans, add); continue;}
        double temp=slope(pp[0], I);
        int cnt=1+add, maxx=1+add;
        for(int j=1; j<pp.size(); j++)
        {
            if(temp+eps>=slope(pp[j], I)&&temp-eps<=slope(pp[j], I)) cnt++;
            else maxx=max(maxx, cnt), temp=slope(pp[j], I), cnt = 1 + add;
        }

        ans=max(ans, cnt);
        ans=max(ans, maxx);
    }

    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mainp();
    return 0;
}

/*
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
*/

