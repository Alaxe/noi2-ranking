#include<bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18 + 17;
const int MAXN=(int)1e5+17;

long long sz[MAXN];
int dig[MAXN];
long long n, k;
string number="";
vector<string> v;

void get(long long lv, long long a)
{
    if(lv==0) return;

    long long c=a/sz[lv-1];
    number+=(char)('0'+dig[c]);
    long long nwa=a-c*sz[lv-1];
    if(c%2==1) nwa=sz[lv-1]-nwa-1;

    get(lv-1, nwa);
}

int raz(string a, string b)
{
    int aa=0, bb=0;
    for(int i=0; i<a.size(); i++) aa+=a[i]-'0';
    for(int i=0; i<b.size(); i++) bb+=b[i]-'0';

    return abs(aa-bb);
}

long long a, b;

void mainp()
{
    cin>>n>>k>>a>>b;
    for(int i=0; i<n; i++) cin>>dig[i];

    sz[0]=1;
    for(int i=1; i<=k; i++)
    {
        if(sz[i-1] >= inf / n) sz[i] = inf;
        else sz[i]=sz[i-1]*n;
    }

    for(int i=a-1; i<=b-1; i++) {number=""; get(k, i); v.push_back(number);}

    string ans1 = v[0];
    for(int i = 0; i < v.size(); i++) ans1 = max(ans1, v[i]);

    cout<<ans1<<" ";

    int Ans = 0;
    for(int i=1; i<v.size(); i++) Ans=max(Ans, raz(v[i-1], v[i]));
    cout<<Ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mainp();
    return 0;
}

/*
3 2 3 5
7 1 5
*/

/*
3 3 10 16
7 1 5
*/
