#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct point
{
    int x,y;
};
int n,ans;
point a[1010];
int det(point a,point b,point c)
{
    return (a.x-b.x)*(a.y-c.y)-(a.y-b.y)*(a.x-c.x);
}
int main( )
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,tmp;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            tmp=0;
            for(k=0;k<n;k++)
            {
                if(det(a[i],a[j],a[k])==0)tmp++;
            }
            if(tmp>ans)ans=tmp;
        }
    }
    cout<<ans<<endl;
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
