#include<bits/stdc++.h>
using namespace std;
vector<int> graf[200005];
bool used1[200005],used2[200005],flag,isfirst;
int maxi=1,br1,br2,start1,start2;
void dfs1(int st)
{
    used1[st]=true;
    br1++;
    for(int i=0; i<graf[st].size(); i++)
    {
        if(!used1[graf[st][i]] && !used2[graf[st][i]]) dfs1(graf[st][i]);
    }
}
void dfs2(int st)
{
    if(isfirst)
    {
        flag=false;
        used2[st]=true;
        br2++;
        if(used1[st]){used1[st]=false; br1--; flag=true;}
        if(br2==br1)
        {
            if(br2>maxi) maxi=br2;
            br2--;
            used2[st]=false;
            if(flag)
            {
                br1++;
                used2[st]=true;
            }
            return;
        }
        else if(br2>br1)
        {
            br2--;
            used2[st]=false;
            if(flag)
            {
                br1++;
                used2[st]=true;
            }
            return;
        }
    }
    else
    {
        br2++;
        used2[st]=true;
    }
    for(int i=0; i<graf[st].size(); i++)
    {
        if(!used2[graf[st][i]] && graf[st][i]!=start1) dfs2(graf[st][i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,beg,en;
    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        cin >> beg >> en;
        graf[beg].push_back(en);
        graf[en].push_back(beg);
    }
    cin >> start1 >> start2;
    used1[start1]=true;
    used2[start2]=true;
    dfs1(start1);
    dfs2(start2);
    if(br1>br2)
    {
        cout << br2 << endl;
        return 0;
    }
    isfirst=true;
    br2=0;
    memset(used2,0,sizeof(used2));
    dfs2(start2);
    cout << maxi << endl;
    return 0;
}
/**
Input:
6
1 2
2 3
3 4
4 5
5 6
4 5
Output:
2

Input:
8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8
Output:
4
*/
