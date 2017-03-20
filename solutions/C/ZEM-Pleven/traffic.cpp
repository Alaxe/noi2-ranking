#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
int n,m;
char ch[645][645];
struct gvr
{
    int n,d=0;
};
vector <gvr> v[410000],vh;
bool f[410000];

void connect(int a,int b,char c)
{
    if(c=='#') return;
    int t;
    if(b==0) t=0;
    else t=c-'A'+1;
    gvr vr;
    vr.n=b;
    vr.d=t;
    v[a].push_back(vr);
}

int tolin(int x,int y)
{
    return (x-1)*m+y;
}

bool fff(gvr a,gvr b)
{
    if(a.d>b.d) return 1;
    return 0;
}

int main()
{
    int i,j,pos;
   // cout<<"start "<<time(NULL)<< endl;
    cin>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin>>ch[i][j];
    /*for(i=0; i<n; i++){
        for(j=0; j<m; j++)
            cout<<a[i][j];
        cout<<endl;
        }*/
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(ch[i][j]!='*')
            {
                if(i==1 || j==1) connect((i-1)*m+j,0,0);
                if(i==n)
                    connect((i-1)*m+j,0,0);
                else
                {
                    if(ch[i+1][j]!='*')
                    {
                        connect((i-1)*m+j,i*m+j,ch[i+1][j]);
                        connect(i*m+j,(i-1)*m+j,ch[i][j]);
                    }
                }
                if(j==m)
                    connect((i-1)*m+j,0,0);
                else
                {
                    if(ch[i][j+1]!='*')
                    {
                        connect((i-1)*m+j,tolin(i,j+1),ch[i][j+1]);
                        connect(tolin(i,j+1),(i-1)*m+j,ch[i][j]);
                    }
                }
                if(ch[i][j]=='#') pos=(i-1)*m+j;
            }
        }
    /*for(i=1; i<=n*m; i++)
    {
        cout<<i<<":"<< endl;
        for(j=0; j<v[i].size(); j++)
        {
            cout<<" "<<v[i][j].n<<" "<<v[i][j].d<< endl;
        }
    }*/
 //   cout<<"strating dijkstra at "<<time(NULL)<< endl;
    gvr vr1,vr2,vr3;
    vr1.n=pos;
    vr1.d=0;
    vh.push_back(vr1);
    make_heap(vh.begin(),vh.end(),fff);
    while(vh.empty()==false)
    {
        vr1=vh.front();
        pop_heap(vh.begin(),vh.end(),fff);
        vh.pop_back();
        if(vr1.n==0)
        {
            //cout<<time(NULL)<< endl;
            cout<<vr1.d<< endl;
            return 0;
        }
        if(f[vr1.n]==1) continue;
        f[vr1.n]=1;
        for(i=0; i<v[vr1.n].size(); i++)
        {
            vr2=v[vr1.n][i];
            if(f[vr2.n]==0)
            {
                vr3.n=vr2.n;
                vr3.d=vr1.d+vr2.d;
                vh.push_back(vr3);
                push_heap(vh.begin(),vh.end(),fff);
            }
        }
    }
    return 0;
}
/*
8 12
NY****AZ****
*SH*D**CHMW*
*CJ**G**LZO*
*JMS****NGG*
*JKPKN#YORC*
************
KJWWGDPLQMXL
TGLAKWQCRQSD

8 12
NY****AA****
*SH*D**AADW*
*CJ**G**LAA*
*JMS****NGA*
*JKPKNAAAA#Z
************
KJWWGDPLQMXL
TGLAKWQCRQSD
*/
