#include<iostream>

using namespace std;

const int MAXN=640;
int n,m;
char k[MAXN+20][MAXN+20];
int minim=-1;
int x,y;
bool used[MAXN+20][MAXN+20];
int mp[MAXN+20][MAXN+20];
int p[MAXN*MAXN+20][3];

void input()
{
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin>>k[i][j];
            if (k[i][j]=='#')
            {
                p[++p[0][0]][0]=0;
                p[p[0][0]][1]=i;
                p[p[0][0]][2]=j;
            }
        }
    }
}

void output()
{
    cout<<minim<<'\n';
}

int searchMin()
{
    int t=-1;
    int curr;
    for (int i=1; i<=p[0][0]; i++)
    {
        if (t>p[i][0] || t==-1) 
        {
            t=p[i][0];
            curr=i;
        }
    }
    return curr;
}

void fill(int d)
{
    bool u=0;
    int x1,y1,st;
    x1=p[d][1];
    y1=p[d][2];
    st=p[d][0];
    p[d][0]=1000000;
    if (x1==0 || x1==n-1 || y1==0 || y1==m-1) 
    {
        minim=st;
        if (k[x1][y1]!='*')return;
    }
    used[x1][y1]=1;
    if (used[x1-1][y1]==0 && k[x1-1][y1]!='*' && (mp[x1-1][y1]>mp[x1][y1]+k[x1-1][y1]-'A'+1 || mp[x1-1][y1]==0))
    {
        if (mp[x1-1][y1]!=0)
        {
            for (int i=1; i<=p[0][0]; i++)
            {
                if (p[i][1]==x1 && p[i][2]==y1) 
                {
                    mp[x1-1][y1]=mp[x1][y1]+k[x1-1][y1]-'A'+1;
                    p[i][0]=mp[x1-1][y1];
                }
            }
        }
        else
        {
            mp[x1-1][y1]=mp[x1][y1]+k[x1-1][y1]-'A'+1;
            p[d][0]=mp[x1-1][y1];
            p[d][1]=x1-1;
            p[d][2]=y1;
            u=1;
        }
        
    }
    if (used[x1+1][y1]==0 && k[x1+1][y1]!='*' && (mp[x1+1][y1]>mp[x1][y1]+k[x1+1][y1]-'A'+1 || mp[x1+1][y1]==0))
    {
        
        if (mp[x1+1][y1]!=0)
        {
            for (int i=1; i<=p[0][0]; i++)
            {
                if (p[i][1]==x1 && p[i][2]==y1) 
                {
                    mp[x1+1][y1]=mp[x1][y1]+k[x1+1][y1]-'A'+1;
                    p[i][0]=mp[x1+1][y1];
                }
            }
        }
        else
        {
            mp[x1+1][y1]=mp[x1][y1]+k[x1+1][y1]-'A'+1;
            if (u==1)
            {
                p[++p[0][0]][0]=mp[x1+1][y1];
                p[p[0][0]][1]=x1+1;
                p[p[0][0]][2]=y1;
            }
            else
            {
                p[d][0]=mp[x1+1][y1];
                p[d][1]=x1+1;
                p[d][2]=y1;
                u=1;
            }
        }
    }
    if (used[x1][y1-1]==0 && k[x1][y1-1]!='*' && (mp[x1][y1-1]>mp[x1][y1]+k[x1][y1-1]-'A'+1 || mp[x1][y1-1]==0)) 
    {
        if (mp[x1][y1-1]!=0)
        {      
            for (int i=1; i<=p[0][0]; i++)
            {
                if (p[i][1]==x1 && p[i][2]==y1) 
                {                   
                    mp[x1][y1-1]=mp[x1][y1]+k[x1][y1-1]-'A'+1;
                    p[i][0]=mp[x1][y1-1];
                }
            }
        }
        else
        {
            mp[x1][y1-1]=mp[x1][y1]+k[x1][y1-1]-'A'+1;
            if (u==1)
            {
                p[++p[0][0]][0]=mp[x1][y1-1];
                p[p[0][0]][1]=x1;
                p[p[0][0]][2]=y1-1;
            }
            else
            {
                p[d][0]=mp[x1][y1-1];
                p[d][1]=x1;
                p[d][2]=y1-1;
                u=1;
            }
        }
    }
    
    if (used[x1][y1+1]==0 && k[x1][y1+1]!='*' && (mp[x1][y1+1]>mp[x1][y1]+k[x1][y1+1]-'A'+1 || mp[x1][y1+1]==0)) 
    {
        if (mp[x1][y1+1]!=0)
        {
            for (int i=1; i<=p[0][0]; i++)
            {
                if (p[i][1]==x1 && p[i][2]==y1) 
                {                            
                    mp[x1][y1+1]=mp[x1][y1]+k[x1][y1+1]-'A'+1;
                    p[i][0]=mp[x1][y1+1];

                }
            }
        }
        else
        {
            mp[x1][y1+1]=mp[x1][y1]+k[x1][y1+1]-'A'+1;
            if (u==1)
            {
                p[++p[0][0]][0]=mp[x1][y1+1];
                p[p[0][0]][1]=x1;
                p[p[0][0]][2]=y1+1;
            }
            else
            {
                p[d][0]=mp[x1][y1+1];
                p[d][1]=x1;
                p[d][2]=y1+1;
                u=1;
            }
        }
    }
}

void solve()
{
    int sm;
    do
    {
        sm=searchMin();        
        fill (sm);
    }
    while (minim==-1);
    /*for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cerr<<mp[i][j]<<' ';
        }
        cout<<endl;
    }*/
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    input();
    solve();
    output();
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
TGLAKBQCRQSD


3 3
AAA
A#A
AAA

3 3
CCC
A#A
AAA
*/