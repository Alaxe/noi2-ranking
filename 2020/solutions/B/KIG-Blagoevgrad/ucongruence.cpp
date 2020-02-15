#include <bits/stdc++.h>
using namespace std;
typedef pair<int,bool> iPair;
int n;
int u;

int distinct(vector<int> nums , bool full)
{
    set<int> dist;
    for(int i : nums)
    {
        dist.insert(i);
    }
    if(full)
    {
        vector<int> p(n);
        for(set<int>::iterator it = dist.begin(); it != dist.end(); ++it)
        {
            cout <<*it <<endl;
        }
    }
    return dist.size();
}


vector< vector<int> > construct(vector<int> nums, int dist)
{
    vector<iPair> g[n];
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(nums[i] < nums[j])
            {
                g[i].push_back(make_pair(j, false));
            }
            else if(nums[i] == nums[j])
            {
                g[i].push_back(make_pair(j, true));
            }
        }

    }
}

unsigned long long C(int k, int n)
{
    unsigned long long comb = 1;
    unsigned long long d = 1;
    for(int i = 0; i < k; i++)
    {
        comb *= (n - i);
        d *= (i + 1);
    }
    return comb / d;
}
int main()
{
cin >>n >>u;
vector<int> nums(n);
for(int i= 0; i < n; i++)
{
    cin >>nums[i];
}
int dist = distinct(nums, true);
unsigned long long needed = (C(dist, u) + 1) / 2;
cout <<dist <<endl;
cout <<needed <<endl;
return 0;
}

