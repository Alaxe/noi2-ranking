#include<bits/stdc++.h>
using namespace std;
int used[2][128][128];
int n,m;
char table[128][128];
pair<int,int>start,final;
int AnswerProblem;
int dir[4][2]={1,0,-1,0,0,-1,0,1};
bool valid_position(int x,int y)
{
    if (x<0||x>=n)
        return false;
    if (y<0||y>=m)
        return false;
    return true;
}
int cntB,cntE;
int main()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)for (int j=0;j<m;j++)
        cin>>table[i][j];
    for (int i=0;i<n;i++)for (int j=0;j<m;j++)
        if (table[i][j]=='B')
        cntB++;
    else
        if (table[i][j]=='E')
        cntE++;
    if (cntB!=1||cntE!=1)
    {
        cout<<-1<<endl;
        return 0;
        ///impossible
    }
    for (int i=0;i<n;i++)for (int j=0;j<m;j++)
        if (table[i][j]=='B')
        start.first=i,start.second=j;
        else
        if (table[i][j]=='E')
        final.first=i,final.second=j;
    used[0][start.first][start.second]=0;
    queue< pair<int,int> >q;queue<bool>q_help;
    q.push(start);
    q_help.push(0);
    used[0][start.first][start.second]=1;
    while (!q.empty())
    {
        pair<int,int>now=q.front();q.pop();
       // cout<<now.first<<" "<<now.second<<endl;
        bool helpB=q_help.front();q_help.pop();
        //cout<<helpB<<endl;
        if (helpB==1)
        for (int help=0;help<4;help++)
        {
            pair<int,int>next;
            next.first=now.first+dir[help][0];
            next.second=now.second+dir[help][1];
            if (!valid_position(next.first,next.second))
                continue;
            if (table[next.first][next.second]=='#')
                continue;
            if (used[1][next.first][next.second])
                continue;
            used[1][next.first][next.second]=used[1][now.first][now.second]+1;
            q.push(next);
            q_help.push(1);
        }
        else
        for (int help=0;help<4;help++)
        {
            for (bool next_help=0;;next_help=1)
            {
                //cout<<"###"<<help<<" "<<next_help<<endl;
                pair<int,int>next;
                next.first=now.first+dir[help][0];
                next.second=now.second+dir[help][1];
                if (!valid_position(next.first,next.second))
                    {if (next_help==1)
                    break;continue;}
                bool next_is_bomb=(table[next.first][next.second]=='#');
                if (next_is_bomb!=next_help)
                    {if (next_help==1)
                    break;continue;}
                if (used[next_help][next.first][next.second])
                    {if (next_help==1)
                    break;continue;}
                used[next_help][next.first][next.second]=used[0][now.first][now.second]+1;
                q.push(make_pair(next.first,next.second));
                q_help.push(next_help);
                if (next_help==1)
                    break;
            }
        }
    }
    if (!used[0][final.first][final.second]&&!used[1][final.first][final.second])
    {
        cout<<-1<<endl;
        return 0;
    }
    if (used[0][final.first][final.second]&&!used[1][final.first][final.second])
        AnswerProblem=used[0][final.first][final.second];
    else
    if (!used[0][final.first][final.second]&&used[1][final.first][final.second])
        AnswerProblem=used[1][final.first][final.second]+2;
    else
    AnswerProblem=min(used[0][final.first][final.second],used[1][final.first][final.second]+2);
    AnswerProblem--;
    cout<<AnswerProblem<<endl;
    return 0;
}
