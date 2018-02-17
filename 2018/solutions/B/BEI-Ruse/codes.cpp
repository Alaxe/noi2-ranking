#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

const long long MAXN=100;
const long long MAXC=1000000000000000000;
long long n, k;
long long b, e;
vector<char> d;
string maxc;
long long sb, w;
bool bg=0;
long long maxs;

void input()
{
    char p;
    cin>>n>>k>>b>>e;
    for (long long i=0; i<n; i++)
    {
        cin>>p;
        d.push_back(p);
    }
}

void output()
{
    for (int i=0; i<w; i++)
        cout<<d[0];
    cout<<maxc<<' '<<maxs<<endl;
}

string generate(long long c)
{
    string t;
    long long p, h=1, mp;
    if (!bg) 
    {
        for (int i=1; i<k; i++)
        {
            if (!(h*n>MAXC || h*n<0)) h*=n;
            else 
            {
                bg=1;
                w=k-i;
                sb=h;
                break;
            }
        }
    }
    else h=sb;
    p=c;
    mp=p/h;
    t=d[p/h];
    while (h>1)
    {
        p=p%h;
        h=h/n;
        if (mp%2!=0) 
        {
            //cerr<<"even"<<endl;
            t=t+d[n-(p/h)-1];
        }
        else
        {
            t=t+d[p/h];
        }
        mp=mp*n+(p/h);
    }
    //cerr<<t<<endl;
    return t;
}

void search_max_sub(string c1, string c2)
{
    long long s1=0, s2=0;
    for (long long i=0; i<c1.size(); i++)
    {
        s1+=c1[i]-'0';
    }
    for (long long i=0; i<c2.size(); i++)
    {
        s2+=c2[i]-'0';
    }
    if (maxs<fabs(s1-s2)) 
    {
        maxs=fabs(s1-s2);
    }
}

void search_max_number(string c)
{
    if (maxc<c) maxc=c;
}

void solve()
{
    if (n==1)
    {
        w=k-1;
        maxc=d[0];
        
    }
    else
    {
        string prev, now;
        for (long long i=b; i<=e; i++)
        {
            now=(generate(i-1));
            search_max_number(now);
            if (i>b) 
            {
                search_max_sub(now, prev);
            }
            prev=now;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    output();
    return 0;
}
/*
3 2 3 5
7 1 5

3 3 10 16
7 1 5
*/