#include <iostream>
#include <algorithm>
using namespace std;
int brk,n;

struct Dv
{
    int x,y,i,j;
} p[1002],k[1000006];

bool eq(Dv a,Dv b)
{
    return a.y*b.x == b.y*a.x ? 1:0;
}

bool fff(Dv a,Dv b)
{
    if(a.x==0 && b.x==0) return a.i < b.i;
    if(a.x==0) return 1;
    if(b.x==0) return 0;
    if(a.y * a.x * b.x * b.x < b.y * b.x * a.x * a.x) return 1;
    if(eq(a,b)) return a.i<b.i;
    return 0;
}

int main()
{
    int ans=2,br,j;
    cin>>n;
    for(int i=0; i<n; i++) cin>>p[i].x>>p[i].y;

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            k[brk].x=p[j].x - p[i].x;
            k[brk].y=p[j].y - p[i].y;
            k[brk].i=i;
            k[brk++].j=j;
        }
    sort(k,k+brk,fff);
    for(int i=0; i<brk; i++)
    {
        j=i;
        br=0;
       // cout<<k[i].x<<k[i].y<< endl;
        while(j<brk && eq(k[i],k[j]) && k[i].i==k[j].i)
        {
            br++; j++;
        }
        i=j-1;
        ans=max(ans,br+1);
    }
    cout<<ans<< endl;
    return 0;
}
/*
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
*/
