#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define karta map
///twitch.tv/bili220022
/**
DM me jordan.iliev501@gmail.com
*/
using namespace std;
void get_69_points()
{
    ll n,k,curr;
    ull res=0;
    cin>>k;
    vector<pair<ll,ll>> lili_e_mega_gotina;
    karta<ll,ll> mp;
    cin>>n>>curr;
    lili_e_mega_gotina.push_back({curr,1});
    for(ll i=1;i<n;i++)
    {
        cin>>curr;
        if(lili_e_mega_gotina[lili_e_mega_gotina.size()-1].first == curr)
        {
            lili_e_mega_gotina[lili_e_mega_gotina.size()-1].second++;
        }
        else
        {
            lili_e_mega_gotina.push_back({curr,1});
        }
        if(lili_e_mega_gotina[lili_e_mega_gotina.size()-1].second>=k)
        {
            mp[lili_e_mega_gotina[lili_e_mega_gotina.size()-1].first]++;
        }
    }
    lili_e_mega_gotina.clear();
    cin>>n>>curr;
    lili_e_mega_gotina.push_back({curr,1});
    for(ll i=1;i<n;i++)
    {
        cin>>curr;
        if(lili_e_mega_gotina[lili_e_mega_gotina.size()-1].first == curr)
        {
            lili_e_mega_gotina[lili_e_mega_gotina.size()-1].second++;
        }
        else
        {
            lili_e_mega_gotina.push_back({curr,1});
        }
        if(lili_e_mega_gotina[lili_e_mega_gotina.size()-1].second>=k)
        {
            res+=mp[lili_e_mega_gotina[lili_e_mega_gotina.size()-1].first];
        }
    }
    cout<<res<<endl;
}
void get_0_points()
{
    ll n,k,curr;
    ull res=0;
    cin>>k;
    deque<ll> lililili;
    karta<deque<ll>,ull> mp;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>curr;
        if(lililili.empty())
        {
            lililili.push_back(curr);
            continue;
        }
        if(lililili.back()>curr)
        {
            lililili.clear();
            lililili.push_back(curr);
        }
        else
        {
            lililili.push_back(curr);
            if(lililili.size()>k)
            {
                lililili.pop_front();
            }
            if(lililili.size()==k)
            {
                mp[lililili]++;
            }
        }
    }/*
    for(auto x:mp)
    {
        auto t = x.first;
        while(!t.empty())
        {
            cout<<t.front()<<" ";
            t.pop_front();
        }
        cout<<endl;
        cout<<"r:"<<x.second<<endl;
    }*/
    lililili.clear();
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>curr;
        if(lililili.empty())
        {
            lililili.push_back(curr);
            continue;
        }
        if(lililili.back()>curr)
        {
            lililili.clear();
            lililili.push_back(curr);
        }
        else
        {
            lililili.push_back(curr);
            if(lililili.size()>k)
            {
                lililili.pop_front();
            }
            if(lililili.size()==k)
            {
                res+=mp[lililili];
            }
        }
    }
    cout<<res<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll w;
    cin>>w;
    if(w%2)
    {
        get_0_points();
    }
    else
    {
        get_69_points();
    }
    return 0;
}
