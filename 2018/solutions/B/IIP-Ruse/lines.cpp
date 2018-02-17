#include <iostream>
using namespace std;
struct devides
{
    int razlikaX;
    int razlikaY;
}razlika;
struct check
{
    int X;
    int Y;
}checkCords;
int main()
{
    int n;
    cin>>n;
    int cords[n-1][2];
    devides cordsDev[n-1][n-1];
    check checking;
    check prevChecking[n-1];
    int prevMax=0,Max=0,time=0;
    for(int i=0;i<n;i++)
    {
        cin>>cords[i][0]>>cords[i][1];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-2;j++)
        {
            cordsDev[i][j].razlikaX=cords[0][0]-cords[j+1][0];
            cordsDev[i][j].razlikaY=cords[0][1]-cords[j+1][1];
        }
    }
    while(true)
    {
        for(int i=0;i<n-1;i++)
        {
            for(int q=0;q<n-2;q++)
            { 
                for(int k=0;k<n-2;k++)
            {
                if(cordsDev[i][q].razlikaX==cordsDev[q+1][k].razlikaX &
                cordsDev[i][q].razlikaY==cordsDev[q+1][k].razlikaY &
                checking.X==cordsDev[i][q].razlikaX &
                checking.Y==cordsDev[i][q].razlikaY)
                {
                    
                    Max++;
                }
            }
            }
        
        if(prevMax<Max)
        {
            
            prevMax=Max;
            Max=0;
        }
        } 
        
        for(int i=0;i<n-1;i++)
        {
            for(int q=0;q<n-2;q++)
            {
                for(int k=0;k<n-2;k++)
            {
                if(cordsDev[i][q].razlikaX==cordsDev[q+1][k].razlikaX &
                cordsDev[i][q].razlikaY==cordsDev[q+1][k].razlikaY &
                prevChecking[time].X!=cordsDev[i][q].razlikaX &
                prevChecking[time].Y!=cordsDev[i][q].razlikaY)
                {
                    checking.X=cordsDev[i][q].razlikaX;
                    checking.Y=cordsDev[i][q].razlikaY;
                    prevChecking[time].X=checking.X;
                    prevChecking[time].Y=checking.Y; 
                }
            }
            }
        
        
        }
        time++;
       if(time>=n-2)
       {
           break;
       } 
    }
cout<<prevMax-1;
}