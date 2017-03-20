#include<bits/stdc++.h>
const long long MOD=123456789012345ll;
const int MAXN=1005;

using namespace std;
int w, h;
int n;

vector<pair<pair<int, int>, int > > ots;

bool cmp(pair<pair<int, int>, int > a, pair<pair<int, int>, int > b)
{
    if(a.first.first<b.first.first) return true;
    if(a.first.first>b.first.first) return false;

    if(a.first.second<b.first.second) return true;
    if(a.first.second>b.first.second) return false;

    if(a.second<b.second) return true;
    if(a.second>b.second) return false;

    return false;
}

void mainp()
{
    cin>>w>>h;
    cin>>n;

    int x, y;
    cin>>x>>y;

    for(int i=1; i<n; i++)
    {
        int x1, y1;
        cin>>x1>>y1;

        if(x==x1)
        {
            ots.push_back(make_pair(make_pair(min(y, y1), max(y, y1)), x));
        }
        x=x1;
        y=y1;
    }

    sort(ots.begin(), ots.end(), cmp);


    for(int i=0; i<ots.size()-1; i++)
    {
        if(ots[i].first.second>ots[i+1].first.first&&ots[i].first.second<ots[i+1].first.second)
        {
            ots[i].first.second=ots[i+1].first.first;
        }
        else if(ots[i].first.second>ots[i+1].first.first&&ots[i].first.second>ots[i+1].first.second)
        {
            ots[i].first.second=ots[i+1].first.first;
        }
    }

    long long sum=0ll;
    for(int i=0; i<ots.size(); i++)
    {
        sum=sum+(long long)(w-ots[i].second)*(abs(ots[i].first.second-ots[i].first.first));
    }

    cout<<sum<<endl;

}

int main()
{
    mainp();
    return 0;
}

/*
15 10
16
6 0
6 2
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10
*/
