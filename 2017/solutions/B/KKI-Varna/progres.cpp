#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
#include<limits>
#include<memory>
#define ost 123456789012345LL
using namespace std;
struct node
{
    int a, raz;
};
int m[1005];
vector<node> v[1000];
int now=0;
int raz[1005]= {0};
unsigned long long dfs(int beg,int kod,int na)
{
    unsigned long long br=0;
    stack<int> st;
    for(int i=0; i<v[beg].size(); i++)
    {
        if(v[beg][i].raz==kod)
        {
            st.push(v[beg][i].a);
            br++;
        }
    }
    int a;
    while(!st.empty())
    {
        a=st.top();
        st.pop();
        for(int i=0; i<v[a].size(); i++)
        {
            if(v[a][i].raz==kod)
            {
                st.push(v[a][i].a);
                br++;
            }
        }
    }
    br%=ost;
    return br;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    node a;
    int maxa=0,mina=10000,mina1=10000;;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>m[i];
        if(m[i]>maxa)maxa=m[i];
        if(m[i]<mina)
        {
            mina1=mina;
            mina=m[i];
        }
        else if(m[i]<mina1)mina1=m[i];
        for(int j=0; j<i; j++)
        {
            if(m[j]<m[i])
            {
                a.a=i;
                a.raz=m[i]-m[j];
                v[j].push_back(a);
            }
        }
    }
    unsigned long long br1=0;
    for(int i=mina1-mina; i<=maxa-mina; i++)
    {
        for(int j=0; j<1005; j++)raz[i]=0;
        for(int beg=0; beg<n; beg++)
        {
            br1+=dfs(beg,i,0);
            br1%=ost;
        }
    }
    cout<<br1<<endl;
}
