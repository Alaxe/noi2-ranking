#include <iostream>
using namespace std;
int n,m,x,y;
int mx[20000],my[20000];
void read()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        mx[i]=x;
        my[i]=y;
    }
}
void solve()
{
    int cnt=0,curr=mx[0];
    int used[10000];
    used[mx[0]]=1;
    for(int i=0; i<m; i++)
    {
        if(used[mx[i]]==used[my[i]])
        {
            break;
        }
        else
        {
            if(mx[i]==curr)
            {
                used[my[i]]==1;
                curr=my[i];
                cnt++;
                break;
            }
            if(my[i]==curr)
            {
                used[my[i]]==1;
                curr=mx[i];
                cnt++;
                break;
            }
        }
    }
    for(int j=0; j<m; j++)
    {
        if(used[mx[j]]==used[my[j]])
        {
            break;
        }
        else
        {
            if(mx[j]==curr)
            {
                used[my[j]]==1;
                curr=my[j];
                cnt++;
                break;
            }
            if(my[j]==curr)
            {
                used[my[j]]==1;
                curr=mx[j];
                cnt++;
                break;
            }
        }
    }
    for(int k=0; k<m; k++)
    {
        if(used[mx[k]]==used[my[k]])
        {
            break;
        }
        else
        {
            if(mx[k]==curr)
            {
                used[my[k]]==1;
                curr=my[k];
                cnt++;
                break;
            }
            if(my[k]==curr)
            {
                used[my[k]]==1;
                curr=mx[k];
                cnt++;
                break;
            }
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    read();
    solve();
    return 0;
}
