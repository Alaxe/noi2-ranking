#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct workers
{
    vector<int> v;
};
struct srt
{
    int x;
    int b;
};
bool cmp(srt a,srt b)
{
    if(a.b>b.b) return true;
    return false;
}

workers a[5000];
srt s[5000];
int mzaplata;
int n,m;
bool u[5000];

void Read()
{
    cin>>n>>mzaplata;
    int k,c;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        s[i].x=i;
        for(int j=0;j<k;j++)
        {
            cin>>c;
            a[c-1].v.push_back(i);
            s[c-1].b++;
        }
    }
}

void Solve()
{
    sort(s,s+n,cmp);
    long long sum=1;
    m=n-1;
    queue<int>c;
    c.push(s[0].x);
    u[s[0].x]=1;
    workers z;
    int br=s[0].x;
    int d=2;
    while(m)
    {
        z=a[c.front()];
        for(int i=0;i<z.v.size();i++)
        {
            if( u[z.v[i]]==1) continue;
            c.push(z.v[i]);
            u[z.v[i]]=1;
            sum+=d;
            m--;
        }
        if(c.front()==br) {d++;br=c.back();}
        c.pop();
    }
    sum=sum*mzaplata;
    cout<<sum<<endl;
}

int main()
{
    Read();
    Solve();
    return 0;
}
