#include<bits/stdc++.h>
using namespace std;

int n,t,maxVis,maxDal;
int brLeft,brRight;

struct boardInfo
{
    int x;
    int y;
    int d;
    int x_end;
};

boardInfo boards[1000002];
int tests[100000];
int stackedX[1000002];
int stackedY[1000002];

void input()
{
    int x_b,y_b,d_b;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x_b>>y_b>>d_b;
        boards[i].x=x_b;
        boards[i].y=y_b;
        boards[i].d=d_b;
        boards[i].x_end=x_b+d_b;
        maxVis=max(maxVis,y_b);
        maxDal=max(maxDal,x_b+d_b);
        for(int j=x_b; j<=x_b+d_b; j++) stackedX[j]++;
        stackedY[y_b]+=d_b;

    }
    maxVis++;
    maxDal++;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>tests[i];
    }
}

/*void search_path(int ballX,int ballY)
{

    while(maxVis)
    {
        int maxY=0;
        int stX=0;
        int fnX=0;
        for(int i=0; i<n; i++)
        {
            if(boards[i].y>maxY && boards[i].x>=ballX && boards[i].x_end<ballX)
            {
                maxY=boards[i].y;
                stX=boards[i].x;
                fnX=boards[i].x_end;
            }
        }

    }
}
*/
void cheat(int BallX)
{
    for(int i=BallX; i>0; i--)
    {
        if(stackedX[i]!=stackedX[i-1])brLeft++;
    }

    for(int i=BallX; i<maxDal; i++)
    {
        if(stackedX[i]!=stackedX[i+1]) brRight++;
    }

}

void tryingToSolveThisFuckingProblemFML()
{
    for(int i=0; i<t; i++)
    {
        cheat(i);
        cout<<min(brLeft,brRight)<<" ";
        cout<<brLeft<<" "<<brRight<<endl;
        brLeft=0;
        brRight=0;

    }

}





int main()
{
    input();
    tryingToSolveThisFuckingProblemFML();
    for(int i=0; i<=maxDal; i++) cout<<stackedX[i]<<" ";
    /*for(int i=0; i<n; i++)
    {
        cout<<boards[i].x<<" "<<boards[i].d<<" "<<boards[i].x_end<<" "<<boards[i].y<<endl;
    }
    cout<<endl;

    for(int i=maxVis;i>=0;i--) cout<<stackedY[i]<<" ";
    */
    return 0;
}

/*

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
