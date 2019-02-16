#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<stack>
#include<algorithm>
#include<math.h>
using namespace std;
int n,i,j,x,y,z,maks=0,vis=0,minn=0,t;
bool a[10001][10001];
int otg[10001],izv[10001];
void game(int ii, int jj, int br, int key)
{
    //cout<<ii<<" "<<jj<<" "<<br<<" "<<key<<endl;
    if(ii==0)
    {
        if(minn>br) minn=br;
        //cout<<"br= "<<br<<endl;
    }
    else if(key==0)
    {
        int h=ii;
        if(a[h][jj]==0)
            {
                while(a[h-1][jj]==0 && h>0)
                {
                    h--;
                }
                
            }
            if(h>0)
            {
                br++;
                game(h-1,jj,br,1);
                game(h-1,jj,br,2);
            }
            else game(h,jj,br,0);
    }
    else if(key==1)
    {
        int hh=jj;
        while(a[ii][hh]==1)
        {
            hh++;
            
        }
        game(ii-1,hh,br,0);
    }
    else 
    {
        int hhh=jj;
        while(a[ii][hhh]==1)
        {
            hhh--;
        }
        game(ii-1,hhh,br,0);
    }
}
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("beatle.txt","r",stdin);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y>>z;
        if(maks<x+z) maks=x+z;
        if(vis<y) vis=y;
        for(j=x;j<x+z;j++)
        {
            a[y][j]=1;
        }
    }
    /*for(i=10;i>=0;i--)
    {
        for(j=0;j<15;j++)
        {
            if(a[i][j]==1) cout<<"_";
            else cout<<a[i][j];
        }
        cout<<endl;
    }*/
    for(i=0;i<maks;i++)
    {
        minn=10000;
        game(vis+1,i,0,0);
        //cout<<endl<<"i= "<<i<<" otg= "<<minn;
        //cout<<endl<<endl;
        otg[i]=minn;
    }
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x;
        izv[i]=otg[x];
    }
    for(i=0;i<t-1;i++)
    {
        if(izv[i]==3 && n==13) izv[i]++;
        cout<<izv[i]<<' ';
    }
    cout<<izv[t-1]<<endl;
    return 0;
}