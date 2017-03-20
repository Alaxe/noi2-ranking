#include <iostream>
using namespace std;
int pole[11000][11000];
int rect[11000][4],otg[11000],otg1[11000];
int x,y,S=1;
int brp, brt,pp;
void populwane(int X, int Y, int W, int H, int st)
{

    if(pole[X][Y]!=-1)
    {
        int k=pole[X][Y];
        for(int i=X; i<X+W; i++)
        for(int j=Y; j<Y+H; j++)
        {
          
            if(pole[i][j]==k){otg[k]--; pole[i][j]=st;}
            otg[st]++;
        }
        
    }
   
   else for(int i=X; i<W+X; i++)
        for(int j=Y; j<H+Y; j++)
            if(pole[i][j]==-1){pole[i][j]=st; otg[st]++; pp--;}
}





int main()
{
    cin>>x>>y;
    cin>>brp;
    pp=x*y;
    for(int i=0; i<x; i++)for(int j=0; j<y; j++)pole[i][j]=-1;
     for(int i=0; i<brp; i++)otg[i]=0;       
    
    for(int i=0; i<brp; i++)
    { 
        for(int j=0; j<4; j++)cin>>rect[i][j];
        populwane(rect[i][0],rect[i][1],rect[i][2],rect[i][3],i);
    }
    
    
  cin>>brt;
   for(int i=0; i<brt; i++)
     {
        int a=0,b=0;
        cin>>a>>b;
        if(pole[a][b]!=-1)otg1[i]=otg[pole[a][b]];
        else otg1[i]=pp;
     }
    
   
   for(int i=0; i<brt; i++)cout<<otg1[i]<<endl;

    
 return 0;
}
