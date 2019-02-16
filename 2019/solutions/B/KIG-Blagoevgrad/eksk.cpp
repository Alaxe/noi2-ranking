#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
int n;
bool s[n][n];//susedi

bool used[n];
queue<int> qa,qb;
vector<int> pathA,pathB;

void dfs(int a)
{
    used[a]=true;
    pathA.push_back(a);
    //pathB.push_back(b);
    //used[b]=true;
    qa.push(a);
    //qb.push(b);
        int cur_a = qa.front();
        //int cur_b = qb.front();
        qa.pop();

        for(int i = 0;  i < n; i++)
        {
            for(int j:pathB)
            {
                if(i==j)
                {

                }
            }
        }
    while(!qa.empty()) //&& !qb.empty())
    {


        //qb.pop();
        /*for(int i = 0; i < n; i++)
        {
            if(i!=a && i!=b)
            {
                if(s[a][i] && !used[i])
                {
                    dfs()
                }
                if(s[b][i] && !used[b])
                {

                }
            }

        }   */
    }


}

int main ()
{
ios_base::sync_with_studio(false);
cin >>n;
for(int i = 0; i < n - 1; i++)
{
    int u,v;
    cin >>u >>v;
    u--; v--;
    s[u][v] = true;
    s[v][u] = true;
}
int a,b;
cin >>a >>b;




return 0;
}




