#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct duska
{
    int x;
    int y;
    int d;
    int minfall;
    bool operator<(const duska &o) const
    {
        return y > o.y;
    }
};

bool cmp(duska a, duska b)
{
    return a.y<b.y;
}

duska j[10001]; /** duski */

int ans[10001];

void tilesbelow(int p)
{
    j[p].minfall=100000;
    bool left=false;
    bool right=false;
    for(int a=p-1; a>=1; a--)
    {

        if(j[a].y==j[p].y)
        {
            continue;
        }
        if(j[p].x>j[a].x&&j[p].x<=j[a].x+j[a].d && left==0)
        {
            //cout<<"Duska s kordinati "<<j[p].x<<" "<<j[p].y<<" pada vyrhu duska s kordinati "<<j[a].x<<" "<<j[a].y<<endl;
            j[p].minfall=min(j[p].minfall,j[a].minfall+1);
            left=true;
        }
        if(j[p].x+j[p].d>=j[a].x&&j[p].x+j[p].d<j[a].x+j[a].d&&right==0)
        {
            //cout<<"Duska s kordinati "<<j[p].x<<" "<<j[p].y<<" "<<" pada vyrhu duska s kordinati "<<j[a].x<<" "<<j[a].y<<endl;
            j[p].minfall=min(j[p].minfall,j[a].minfall+1);
            right=true;
        }
        if(left && right)
        {
            break;
        }
    }
    if(left==false||right==false)
        j[p].minfall=1;
}

void firstfall(int tjx, int ansnumber)
{
    for(int l=n; l>=1; l--)
    {
        if(tjx>=j[l].x&&tjx<j[l].x+j[l].d)
        {
            ans[ansnumber]=j[l].minfall;
            break;
        }
    }
}

int main ()
{

    cin>>n;
    int i=1;

    for(i=1; i<=n; i++)
    {
        cin>>j[i].x>>j[i].y>>j[i].d;
        j[i].minfall=0;
    }


    sort(j,j+n,cmp);



    for(int i=1; i<=n; i++)
    {
        if(j[i].y==1)
        {
            j[i].minfall=1;
            continue;
        }
        tilesbelow(i);
    }

    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int tj;
        cin>>tj;
        firstfall(tj,i);
    }

    cout<<ans[1];
    for(int i=2; i<=t; i++)
        cout<<" "<<ans[i];
    cout<<endl;

    return 0;
}
/**
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11
*/
