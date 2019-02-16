#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int bre[50001];
int che[50001];
map< pair<int,int>,bool > used;
int ch,nech,z;
vector< int > AL[50001];
vector< int > cres;
int n,m;
int res;
int idk(int x)
{
    //cout<<x<<endl;
    cres.push_back(x);
    int lal=AL[x].size();
    for(int i=0; i<AL[x].size(); i++)
    {
        pair<int,int> c;
        c.first=min(x,AL[x][i]);
        c.second=max(x,AL[x][i]);
        if( used[c] == 0)
        {
            used[c]=1;
            if(che[x]==1)
            {
                che[x]=0;
                bre[x]--;
            }
            else
            {
                if(che[x]==0)
                {
                    if(bre[x]==1)
                    {
                        che[x]=-1;
                        z++;
                    }
                    else
                        che[x]=1;
                    bre[x]--;
                }
            }
            ///
            if(che[AL[x][i]]==1)
            {
                che[AL[x][i]]=0;
                bre[AL[x][i]]--;
            }
            else
            {
                if(che[AL[x][i]]==0)
                {
                    if(bre[AL[x][i]]==1)
                    {
                        che[AL[x][i]]=-1;
                        z++;
                    }
                    else
                        che[AL[x][i]]=1;
                    bre[AL[x][i]]--;
                }
            }
            if(idk(AL[x][i])==4)
                return 4;
        }
    }
    return 4;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
        AL[b].push_back(a);
        bre[a]++;
        bre[b]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(bre[i]%2==0)
        {
            ch++;
            che[i]=1;
        }
        else
        {
            nech++;
        }
    }
    if(nech>0)
    {
        res=nech/2;
    }
    else
        res=1;
    cout<<res<<endl;
    //int try1=5;
    while(z!=n)
    {
        //sort(che,che+n);
        for(int i=1; i<=n; i++)
        {
            /*cout<<"ch:\n";
            for(int i=1; i<=n; i++)
            {
                cout<<che[i]<<endl;
            }
            cout<<"dsfdg";*/
            if(che[i]==0)
            {
                cres.clear();
                idk(i);
                int cl=cres.size();
                cout<<cl;
                for(int j=0; j<cl; j++)
                {
                    cout<<" "<<cres[j];
                }
                cout<<endl;
                break;
            }
        }
        //try1--;
    }
    return 0;
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
