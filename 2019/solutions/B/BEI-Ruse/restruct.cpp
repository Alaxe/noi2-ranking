#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 5000;
int n, k;
vector<int> ch[MAXN+100];
bool used[MAXN+100];
int check, sb;
unsigned long long br;

void input()
{
    int temp, temp2;
    cin>>n>>k;
    for (int i=0; i<n; i++)
    {
        cin>>temp;
        for (int j=0; j<temp; j++)
        {
            cin>>temp2;
            ch[temp2-1].push_back(i);
        }
    }
}

void output()
{
    cout<<br<<endl;
}

void zeroing()
{
    for (int i=0; i<n; i++)
    {
        used[i]=0;
    }
    check = 0;
    sb = 0;
}

int dfs(int curr)
{
    check++;
    int c=0;
    used[curr] = 1;
    for (int i=0; i<ch[curr].size(); i++)
    {
        if (!used[ch[curr][i]]) c += dfs(ch[curr][i]); 
    }
    c++;
    sb += c;
    return c;
}

void solve()
{
    /*for (int i=0; i<n; i++)
    {
        cerr<<i<<" - ";
        for (int j=0; j<ch[i].size(); j++)
        {
            cerr<<ch[i][j]<<' ';
        }
        cerr<<endl;
    }*/
    int temp;
    for (int i=0; i<n; i++)
    {
        zeroing();
        dfs(i);
        temp = sb;
        if ((br>temp || !br) && check==n) br = temp;
    }
    br *= k;
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
4 100
1 4
3 1 3 4
2 1 2
1 3

12 100
1 12
1 1
1 2
1 2
1 2
1 2
1 1
1 7
1 7
1 7
1 3
1 11
*/