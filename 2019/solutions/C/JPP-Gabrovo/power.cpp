#include<iostream>
#include<utility>
#include<vector>
#include<map>
using namespace std;

const int MAXN=10005;

int a[MAXN];
vector< pair<int,int> > d[45]; // first - number, second - power
map<int,int> m;

void decomposition()
{
    d[2].push_back(make_pair(2,1));
    d[3].push_back(make_pair(3,1));
    d[4].push_back(make_pair(2,2));
    d[5].push_back(make_pair(5,1));
    d[6].push_back(make_pair(2,1)); d[6].push_back(make_pair(3,1));
    d[7].push_back(make_pair(7,1));
    d[8].push_back(make_pair(2,3));
    d[9].push_back(make_pair(3,2));
    d[10].push_back(make_pair(2,1)); d[10].push_back(make_pair(5,1));
    d[11].push_back(make_pair(11,1));
    d[12].push_back(make_pair(2,2)); d[12].push_back(make_pair(3,1));
    d[13].push_back(make_pair(13,1));
    d[14].push_back(make_pair(2,1)); d[14].push_back(make_pair(7,1));
    d[15].push_back(make_pair(3,1)); d[15].push_back(make_pair(5,1));
    d[16].push_back(make_pair(2,4));
    d[17].push_back(make_pair(17,1));
    d[18].push_back(make_pair(2,1)); d[18].push_back(make_pair(3,2));
    d[19].push_back(make_pair(19,1));
    d[20].push_back(make_pair(2,2)); d[20].push_back(make_pair(5,1));
    d[21].push_back(make_pair(3,1)); d[21].push_back(make_pair(7,1));
    d[22].push_back(make_pair(2,1)); d[22].push_back(make_pair(11,1));
    d[23].push_back(make_pair(23,1));
    d[24].push_back(make_pair(2,3)); d[24].push_back(make_pair(3,1));
    d[25].push_back(make_pair(5,2));
    d[26].push_back(make_pair(2,1)); d[26].push_back(make_pair(13,1));
    d[27].push_back(make_pair(3,3));
    d[28].push_back(make_pair(2,2)); d[28].push_back(make_pair(7,1));
    d[29].push_back(make_pair(29,1));
    d[30].push_back(make_pair(2,1)); d[30].push_back(make_pair(3,1)); d[30].push_back(make_pair(5,1));
    d[31].push_back(make_pair(31,1));
    d[32].push_back(make_pair(2,5));
    d[33].push_back(make_pair(3,1)); d[33].push_back(make_pair(11,1));
    d[34].push_back(make_pair(2,1)); d[34].push_back(make_pair(17,1));
    d[35].push_back(make_pair(5,1)); d[35].push_back(make_pair(7,1));
    d[36].push_back(make_pair(2,2)); d[36].push_back(make_pair(3,2));
    d[37].push_back(make_pair(37,1));
    d[38].push_back(make_pair(2,1)); d[38].push_back(make_pair(19,1));
    d[39].push_back(make_pair(3,1)); d[39].push_back(make_pair(13,1));
    d[40].push_back(make_pair(2,3)); d[40].push_back(make_pair(5,1));
    d[41].push_back(make_pair(41,1));
    d[42].push_back(make_pair(2,1)); d[42].push_back(make_pair(3,1)); d[42].push_back(make_pair(7,1));
}

unsigned long long power(int a,int p)
{
    unsigned long long res=1;
    unsigned long long x=a;
    while(p)
    {
        if(p&1) res=res*x;
        p=p>>1;
        x=x*x;
    }
    return res;
}

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    decomposition();

    for(int i=0; i<n; i++)
    {
        cin >> a[i];

        if(a[i]==1) continue;

        for(int j=0; j<d[a[i]].size(); j++)
            if(m[d[a[i]][j].first]<d[a[i]][j].second/k+(d[a[i]][j].second%k!=0?1:0)) m[d[a[i]][j].first]=d[a[i]][j].second/k+(d[a[i]][j].second%k!=0?1:0);
    }

    unsigned long long ans=1;
    for(map<int,int> :: iterator it=m.begin(); it!=m.end(); it++)
        ans=ans*power(it->first,it->second);

    cout << ans << endl;

    return 0;
}
