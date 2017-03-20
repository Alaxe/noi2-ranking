#include<iostream>
using namespace std;
struct dz
{
    int nst,sst;
    bool used;
};
dz park[650][650];
int main()
{
    int n,m,x,y;
    char c;
    cin>>n>>m;
    for(int a=0; a<n ; a++)
    {
        for(int b=0; b<m; b++)
        {
            cin>>c;
            if(c=='*')park[a][b].nst=-1;
            if(c=='*')park[a][b].sst=-1;
            else if(c=='#')
            {
                park[a][b].nst=0;
                park[a][b].sst=0;
                x=a;
                y=b;
            }
            else
            {
                park[a][b].nst=c-'A'+1;
                park[a][b].sst=c-'A'+1;
            }
            park[a][b].used=false;
        }
    }

    bool f=false;
    /*for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
            cout<<park[a][b]<<" ";
            cout<<endl;
    }*/


    for(int a=y+1; a<m; a++)
    {
        if(park[x][a].nst==-1)break;
        park[x][a].sst=park[x][a].nst+park[x][a-1].sst;
        park[x][a].used=true;
    }
    for(int a=y-1; a>=0; a--)
    {
        if(park[x][a].nst==-1)break;
        park[x][a].sst=park[x][a].nst+park[x][a+1].sst;
        park[x][a].used=true;
    }
    bool w=false;
    for(int a=x-1; a>=0; a--)
    {
        w=false;
        for(int b=0; b<m; b++)
        {
            if(park[a][b].nst>0)w=true;
            if(park[a][b-1].nst<0 && park[a+1][b].nst<0 && b>0)continue;
            if(park[a][b].nst==-1 )continue;
            else
            {
                if(park[a+1][b].nst>0)
                {
                    park[a][b].sst=park[a][b].nst+park[a+1][b].sst;
                    park[a][b].used=true;

                }
                if(b>0 && park[a][b-1].nst>0 && park[a][b-1].used==true)
                {
                    park[a][b].sst=min(park[a][b].sst,park[a][b].nst+park[a][b-1].sst);
                    park[a][b].used=true;
                }
            }
        }
        for(int b=0; b<m-1; b++)
        {
            if(park[a][b].nst<0 || park[a][b+1].nst<0)continue;
            else
            {
                if(park[a][b].used==true)park[a][b].sst=min(park[a][b].sst,park[a][b].nst+park[a][b+1].sst);
                else park[a][b].sst+=park[a][b+1].sst;
                park[a][b].used=true;
            }
        }
        if(w==false)break;
    }


    for(int a=x+1; a<n; a++)
    {
        w=false;
        for(int b=0; b<m; b++)
        {
            if(park[a][b].nst>0)w=true;
            if(park[a][b-1].nst<0 && park[a-1][b].nst<0 && b>0)continue;
            if(park[a][b].nst==-1 )continue;
            else
            {
                if(park[a-1][b].nst>0)
                {
                    park[a][b].sst=park[a][b].nst+park[a-1][b].sst;
                    park[a][b].used=true;

                }
                if(b>0 && park[a][b-1].nst>0 && park[a][b-1].used==true)
                {
                    park[a][b].sst=min(park[a][b].sst,park[a][b].nst+park[a][b-1].sst);
                    park[a][b].used=true;
                }
            }
        }
        for(int b=0; b<m-1; b++)
        {
            if(park[a][b].nst<0 || park[a][b+1].nst<0)continue;
            else
            {
                if(park[a][b].used==true)park[a][b].sst=min(park[a][b].sst,park[a][b].nst+park[a][b+1].sst);
                else park[a][b].sst+=park[a][b+1].sst;
                park[a][b].used=true;
            }
        }
        if(w==false)break;
    }

    int q=100000000;
    for(int a=0; a<n; a++)
    {
        if(a==0 || a==n-1)
        {
            for(int b=0; b<m; b++)
            {
                if(park[a][b].used==true)q=min(q,park[a][b].sst);
            }
        }
        else
        {
            if(park[a][0].used==true)q=min(q,park[a][0].sst);
            if(park[a][m-1].used==true)q=min(q,park[a][m-1].sst);
        }
    }
    cout<<q<<endl;
    return 0;
}
/**
8 12
NY****AZ****
*SH*D**CHMW*
*CJ**G**LZO*
*JMS****NGG*
*JKPKN#YORC*
************
KJWWGDPLQMXL
TGLAKBQCRQSD
*/
