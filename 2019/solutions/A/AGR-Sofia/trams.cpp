#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 50100;
const int maxm = 100100;
int n, m;

queue<int> v[maxn];
vector<pair<int,int> > e;
bool used[maxm];
int nume[maxn];
bool touched[maxn];

vector<int> vpaths[maxn];
bool printed[maxn];

vector<vector<int> > paths;

vector<int> new_path(int start, bool line)
{
    int i = start, j , other;
    vector<int> path;
    if(line)    path.push_back(i);
    do
    {
        do
        {
            j = v[i].front();
            v[i].pop();
        }while(used[j]);
        used[j] = true;
        other = (i == e[j].first? e[j].second : e[j].first);
        path.push_back(other);
        nume[i] --;
        nume[other] --;
        touched[i] = true;
        touched[other] = true;
        i = other;
    }while(line? (nume[i] % 2 == 1): (nume[i] != 0));
    return path;
}

void add(vector<int>& x,  int i)
{
    x.push_back(i + 1);
    if(!printed[i])
    {
        printed[i] = true;
        for(int j = 0; j < vpaths[i].size(); j ++)
        {
            add(x, vpaths[i][j]);
        }
    }
    printed[i] = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        v[a].push(e.size());
        v[b].push(e.size());
        nume[a] ++;
        nume[b] ++;
        e.push_back(pair<int,int>(a,b));
    }
    for(int i = 0; i < n; i ++)
    {
        if(nume[i] % 2 == 1)
        {
            paths.push_back(new_path(i, true));
        }
    }

    for(int i = 0; i < n; i ++)
    {
        if(nume[i] != 0 && touched[i])
        {
            vpaths[i] = new_path(i, false);
        }
    }
    for(int i = 0; i < n; i ++)
    {
        if(nume[i] != 0)
        {
            vpaths[i] = new_path(i, false);
        }
    }


    if(paths.size() >= 1)
    {
        cout << paths.size() << endl;
        for(int i = 0; i < paths.size(); i ++)
        {
            vector<int> prt;
            for(int j = 0; j < paths[i].size(); j ++)
            {
                int ver = paths[i][j];
                add(prt, ver);
                //cout << ver + 1 << " ";
            }
            cout << prt.size() << " ";
            for(int j = 0; j < prt.size(); j ++)
            {
                cout << prt[j] << " ";
            }
            cout << endl;
        }
    } else {
        vector<int> prt;
        add(prt, 0);
        cout << 1 << endl;
        cout << prt.size() << " ";
        for(int i = 0; i < prt.size(); i ++)
        {
            cout << prt[i] << " ";
        }

    }
}

/**
8 12
2 3
3 4
5 4
2 6
4 8
6 8
8 7
5 7
6 7
1 2
1 5
1 3
*/
/**
4 5
1 2
1 3
1 4
2 3
3 4
*/
/**
4 4
3 4
1 3
1 2
2 3
*/
