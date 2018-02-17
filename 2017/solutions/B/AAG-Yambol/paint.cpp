#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
// rabotnoto pole sushto shte bude pravougulnik
struct rectangle{
 int x;    // koordinate na goren lqv ugul
 int y;
 int w;
 int h;
};
vector <rectangle> rect;
int n,t;
int parent[11005]; // matrioshki
struct side{
 int x1;  // the coordinates of gorna strana
 int y1;
 int x2;
 int y2;
 int x3;
 int y3;
 int x4;
 int y4; // the coordinates of dolna strana

 int p; // pravougulnik na koito prinadleji
};
vector <side> sides;
long long children[11005]; // the lice of the children
int FindClosest(int x,int y)  // finds the closest horizontal side that covers x,y
{
   int closest=INT_MAX,closesti;
   int i;
   for(i=0;i<sides.size();i++)
   {
       if(sides[i].y1<y && sides[i].y3>y)
        if(sides[i].x1<x && sides[i].x2>x)
         if(y-sides[i].y1<closest)
         {
           closest=y-sides[i].y1;
           closesti=i;
         }
   }
   return closesti;
}
int main()
{
    int i,j;
    rectangle temp;
    cin>>temp.w>>temp.h;
    temp.x=0;
    temp.y=0;
    rect.push_back(temp);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&temp.x,&temp.y,&temp.w,&temp.h);
        rect.push_back(temp);
    }
    side tempside;
    for(i=0;i<n+1;i++)
    {
        tempside.x1=rect[i].x;
        tempside.y1=rect[i].y;
        tempside.x2=rect[i].x+rect[i].w;
        tempside.y2=rect[i].y;

        tempside.x3=rect[i].x;
        tempside.y3=rect[i].y+rect[i].h;
        tempside.x4=rect[i].x+rect[i].w;
        tempside.y4=rect[i].y+rect[i].h;

        tempside.p=i;
        sides.push_back(tempside);

    }
   /* for(i=0;i<n+1;i++)
    {
        cout<<endl;
        cout<<sides[i].x1<<" "<<sides[i].y1<<" "<<sides[i].x2<<" "<<sides[i].y2<<endl;
        cout<<sides[i].x3<<" "<<sides[i].y3<<" "<<sides[i].x4<<" "<<sides[i].y4<<endl;
        cout<<sides[i].p<<endl;
        cout<<endl;
    }*/
    for(i=1;i<n+1;i++)
    {
        parent[i]=FindClosest(rect[i].x,rect[i].y);
       // cout<<parent[i]<<endl;
    }
    for(i=1;i<=n;i++)
    {
        children[parent[i]]+=rect[i].w*rect[i].h;
    }
    /*for(i=0;i<=n;i++)
     cout<<children[i]<<endl;*/
    int qx,qy,k;
    long long ans;
    cin>>t;
    //cout<<children[1]<<endl;
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&qx,&qy);
        k=FindClosest(qx,qy);
        ans=rect[k].w*rect[k].h;
        ans=ans-children[k];
        cout<<ans<<endl;
    }
    return 0;
}

/*

11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3

*/
