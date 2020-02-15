#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>

#define int long long

using namespace std;

const int maxn = 100100;
int n, m;

unordered_set<int> e[maxn];
bool vis[maxn];
int num[maxn];
int first[maxn];
int from[maxn];
int curr = 0;

int delete_crit()
{
    stack<int> st, ord;
    st.push(0);
    ord.push(0);
    from[0] = -1;
    while(!st.empty())
    {
        int t = st.top();
        st.pop();

        if(vis[t])  continue;

        //cout << "! " << t << endl;
        vis[t] = true;
        num[t] = first[t] = curr++;
        ord.push(t);

        for(auto i: e[t])
        {
            if(!vis[i])
            {
                st.push(i);
                from[i] = t;
            } else {
                if(i != from[t])
                {
                    first[t] = min(first[t], first[i]);
                }
            }
        }
    }
    while(!ord.empty())
    {
        int t = ord.top();
        ord.pop();

        for(auto i: e[t])
        {
            if(i != from[t])
            {
                first[t] = min(first[t], first[i]);
            }
        }
    }
    for(int i = 0; i < n; i ++)
    {
        //cout << i << ": " << num[i] << " " << first[i] << endl;
        if(first[i] == num[i] && from[i] != -1)
        {
            //cout << i << " - " << from[i] << endl;
            e[from[i]].erase(i);
            e[i].erase(from[i]);
        }
    }
}

bool vis2[maxn];
int dfs(int fr)
{
    stack<int> st;
    st.push(fr);
    vis2[fr] = true;
    int cnt = 0;
    while(!st.empty())
    {
        int t = st.top();
        st.pop();

        cnt ++;
        for(auto i: e[t])
        {
            if(!vis2[i])
            {
                vis2[i] = true;
                st.push(i);
            }
        }
    }
    return cnt;
}

#undef int
int main()
{
#define int long long
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < m;i ++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;

        e[a].insert(b);
        e[b].insert(a);
    }
    delete_crit();
    /*for(int i = 0; i < n; i ++)
    {
        cout << i << ": ";
        for(auto j: e[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }*/
    int ans = 0;
    for(int i = 0; i < n ; i ++)
    {
        if(!vis2[i])
        {
            int t = dfs(i);
            ans += (t * (t - 1)) / 2;
        }
    }
    cout << ans;
}
/**
5 5
1 2
2 3
3 1
2 4
2 5
*/
/**
7 9
1 2
1 3
2 3
2 4
3 4
5 6
5 7
6 7
5 2
*/
