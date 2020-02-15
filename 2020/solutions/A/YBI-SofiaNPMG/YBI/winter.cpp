#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define LILI_E_GOTINA int
///twitch.tv/bili220022
/**
DM me jordan.iliev501@gmail.com
*/
using namespace std;
ull lili_sarce=0;
ull cnt=0;
struct edge
{
    ll fr,to;
    ll prv=-1;
    LILI_E_GOTINA dangerous=0;///-1 ne lili 0 nz dali lili 1 lili
    bool passable=true;
    edge(ll f,ll t,ll pr)
    {
        fr=f;
        to=t;
        prv=pr;
    }
};

vector<edge>E;
vector<ll> last(100000,-1);
bitset<100000> visited;
bool find_path(LILI_E_GOTINA curr,LILI_E_GOTINA dest,LILI_E_GOTINA last_edge_id)
{
    visited[curr]=1;
    if(curr==dest)
    {
        E[last_edge_id].dangerous=-1;
        return true;
    }
    LILI_E_GOTINA lili_e_super_besto=last[curr];
    while(lili_e_super_besto!=-1)
    {
        if(!E[lili_e_super_besto].passable)
        {
            lili_e_super_besto=E[lili_e_super_besto].prv;
            continue;
        }
        if(visited[E[lili_e_super_besto].to]==0)
        {
            if(find_path(E[lili_e_super_besto].to,dest,lili_e_super_besto))
            {
                E[last_edge_id].dangerous=-1;
                return true;
            }
        }
        lili_e_super_besto=E[lili_e_super_besto].prv;
    }
    return false;
}
void explore(LILI_E_GOTINA curr)
{
    visited[curr]=1;
    cnt++;
    LILI_E_GOTINA lili_e_super_besto = last[curr];
    while(lili_e_super_besto!=-1)
    {
        if(!visited[E[lili_e_super_besto].to] and E[lili_e_super_besto].dangerous!=1)
        {
            explore(E[lili_e_super_besto].to);
        }
        lili_e_super_besto=E[lili_e_super_besto].prv;
    }
}
LILI_E_GOTINA main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    ll m;
    cin>>n;
    cin>>m;
    ll u,v;
    for(ll i=0; i<m; i++)
    {
        cin>>u>>v;
        u--;
        v--;
        E.push_back(edge(u,v,last[u]));///u->v
        last[u]=E.size()-1;
        E.push_back(edge(v,u,last[v]));///v->u
        last[v]=E.size()-1;
    }
    for(ll i=0; i<E.size(); i++)
    {
        if(E[i].fr>E[i].to)
        {
            continue;
        }
        /// fr<to
        if(E[i].dangerous==0)
        {
            E[i].passable=false;
            if(find_path(E[i].fr,E[i].to,i))
            {
                E[i].dangerous=-1;
            }
            else
            {
                E[i].dangerous=1;
            }
            E[i].passable=true;
            visited.reset();
        }
        E[i^1].dangerous=E[i].dangerous;
    }
    for(auto x:E)
    {
        //cout<<x.fr<<" "<<x.to<<" "<<x.dangerous<<endl;
        if(x.dangerous==1)
        {
            x.passable=false;
        }
    }
    for(LILI_E_GOTINA i=0;i<n;i++)
    {
        if(!visited[i])
        {
            ll prv_cnt=cnt;
            explore(i);
            //cout<<cnt-prv_cnt<<endl;
            lili_sarce+=((cnt-prv_cnt-1)*(cnt-prv_cnt))/2;
        }
    }
    cout<<lili_sarce<<endl;
    return 0;
}
