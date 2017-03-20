#include<iostream>
#include<vector>
using namespace std;
struct coord
{
    int i,j;
};
coord tst;

int n,m;
char c;
int  vhod[690][690];
int sm,sn;
bool check(int i,int j, vector<coord> a)
{
    for(int k=0; k<a.size(); k++)
    {
        if(a[k].i==i&&a[k].j==j)
        {
            return false;
        }
    }
    return true;
}
int printpath(vector<coord> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i].i<<" "<<a[i].j<<endl;
    }
}
long long  rek(int i,int j,long long sum,vector<coord> a)
{
    int res=-4;
    int tt;
    sum+=vhod[i][j];
    tst.i=i;
    tst.j=j;
    a.push_back(tst);
    if(i==0 or j==0 or i==m-1 or j==n-1)
    {
        if(vhod[i][j]!=-1)
        {
           return sum;
        }

    }
    if(vhod[i+1][j]>0&&check(i+1,j,a))///right
    {
        tt=rek(i+1,j,sum,a);
           if(res<0||res>tt)
        {
            res=tt;
        }
    }
    if(vhod[i-1][j]>0&&check(i-1,j,a))///left
    {
        tt=rek(i-1,j,sum,a);
           if(res<0||res>tt)
        {
            res=tt;
        }
    }
    if(vhod[i][j-1]>0&&check(i,j-1,a))///up
    {
        tt=rek(i,j-1,sum,a);
           if(res<0||res>tt)
        {
            res=tt;
        }
    }

    if(vhod[i][j+1]>0&&check(i,j+1,a))///down
    {
        tt=rek(i+1,j,sum,a);
           if(res<0||res>tt)
        {
            res=tt;
        }
    }
    if(res==-4)
    {
        return 100000000000;
    }
    return res;
}
int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<m; i++)
        {
            cin>>c;
            if(c=='#')
            {
                vhod[i][j]=0;
                sm=i;
                sn=j;
            }
            else if(c=='*')
            {
                vhod[i][j]=-1;
            }
            else
            {
                vhod[i][j]=c-'A'+1;
            }
        }
    }
    if(sm==0 or sn==0 or sm==m-1 or sn==n-1)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<coord>ss;
    cout<<rek(sm,sn,0,ss)<<endl;
}
