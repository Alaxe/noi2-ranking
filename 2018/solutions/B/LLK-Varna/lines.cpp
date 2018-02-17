#include<iostream>
using namespace std;
struct point
{
    int x;
    int y;
};
int  Des (point a, point b, point c)
{
    int D;
    D= a.x*b.y+a.y*c.x+b.x*c.y;
    D-=(c.x*b.y+c.y*a.x+b.x*a.y);
    return D;
}
point p[1000];
short used[1000][1000];
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int a=0; a<n; a++)
        cin>>p[a].x>>p[a].y;

    int br=0;
    int ans=0;
    for(int a=0; a<n-2; a++)
    {

        for(int b=a+1; b<n-1; b++)
        {
            br=2;
            if(used[a][b]==1)continue;
            for(int c=b+1; c<n; c++)
            {
                if(Des(p[a],p[b],p[c])==0)
                {
                    used[b][c]=1;
                    used[a][c]=1;
                    br++;
                    ///cout<<a<<" "<<b<<" "<<c<<endl;
                }
            }
            ans=max(ans,br);
        }
    }
    cout<<ans<<"\n";
    return 0;
}


/**
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
*/
