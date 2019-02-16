#include<bits/stdc++.h>
using namespace std;
struct waveparticle
{
    long long pos;
    long long wave;
};
const long long golemo = 2750001;
vector<vector<long long> > adj;
vector<long long> cost;
vector<long long>edge;
long long waveprime[5020];
void reset(long long n)
{
    for(int i=0;i<n;i++)
    {
        waveprime[i] = golemo;
    }
}
bool fullfill(long long n)
{
    for(int i=0;i<n;i++)
    {
        if(waveprime[i]==golemo)return false;
       //cout<<4<<endl;
    }
    return true;
}
long long waveFinder_bfs(long long firstvert,long long n)
{
   // cout<<2<<endl;
    reset(n);
    edge = vector<long long>();
    long long currentwave = 0;
    queue<waveparticle> q;
    waveparticle current,helper;for(int i=0;i<n;i++)
    {
        waveprime[i] = golemo;
    }
    current.pos = firstvert;
    current.wave = 0;
    waveprime[firstvert] = 0;
    q.push(current);

    while(!q.empty())
    {
        current = q.front();
        //cout<<"~ "<<current.pos<<endl;
        for(long long i=0;i<adj[current.pos].size();i++)
        {
            if(waveprime[adj[current.pos][i]]>current.wave+1)
            {
                helper.pos = adj[current.pos][i];
                helper.wave = current.wave+1;
                waveprime[helper.pos] = helper.wave;
                if(currentwave<helper.wave)
                {
                    currentwave = helper.wave;
                    edge.push_back(0);
                    //cout<<currentwave<<endl;
                }
                if(currentwave != 0)edge[currentwave-1]++;
                if(fullfill(n))break;
                q.push(helper);
            }
        }
        q.pop();
        //cout<<"hey"<<endl;
    }
    long long conq = 2*n-1;
    for(int i=1;i<edge.size();i++)
    {
        conq += i*edge[i];
    }
    return fullfill(n)?conq:golemo;
}
long long calculateCosts(long long n)
{
    cost.push_back(2*n - 1);
    long long fibonaciScalar = 1;
    for(int i=0;i<n;i++)
    {
        cost.push_back(cost.back()+fibonaciScalar);
        fibonaciScalar++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    long long n,k,input;
    long long nprime;

    cin>>n>>k;

    calculateCosts(n);
    for(long long i=0;i<n;i++)adj.push_back(vector<long long>());
    for(long long i=0;i<n;i++)
    {
        cin>>nprime;
        for(long long j=0;j<nprime;j++)
        {
            cin>>input;
            adj[input - 1].push_back(i);
        }
    }
    long long min_wave = waveFinder_bfs(0,n);
    for(int i=1;i<n;i++)
    {
        long long curr = waveFinder_bfs(i,n);
        if(curr < min_wave)min_wave = curr;
    }
    cout<<k*min_wave<<endl;

    return 0;
}
/*
4 100
1 4
3 1 3 4
2 1 2
1 3

5 1
5 1 2 3 4 5
5 1 2 3 4 5
5 1 2 3 4 5
5 1 2 3 4 5
5 1 2 3 4 5

*/
