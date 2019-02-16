#include <iostream>
#include <cstddef>

using namespace std;

int DetermineShortestPath(int,int,int);
struct board
{
    int xStart, xEnd, y;
};
int maxHeight = 0;

static struct board allBoards[100000];
int main()
{

    int n;
    cin>>n;

    // input

    for(int i = 0 ; i< n; i++)
    {
        cin>>allBoards[i].xStart;
        int height;
        cin>>height;
        if(height > maxHeight)
        {
            maxHeight = height;
        }
        allBoards[i].y = height;
        int length;
        cin>>length;
        allBoards[i].xEnd = allBoards[i].xStart + length;
    }

    // end of input
    int tests;
    cin>>tests;

    for(int i = 1; i <= tests ; i++)
    {
        int fallingIndex;
        cin>>fallingIndex;

        int shortestPath = 0;
        shortestPath = DetermineShortestPath(fallingIndex, n, maxHeight);
        cout<<shortestPath<<" ";
    }
}

int DetermineShortestPath(int fallingIndex, int n, int height)
{
    board currentBoard;
    currentBoard.y = 0;
    int maxHeight =  0;
    for(int i = 0 ; i < n ; i++)
    {
        if(allBoards[i].xStart<= fallingIndex && allBoards[i].xEnd > fallingIndex && allBoards[i].y > maxHeight && allBoards[i].y <= height)
        {
            currentBoard.y = allBoards[i].y;
            currentBoard.xStart = allBoards[i].xStart;
            currentBoard.xEnd = allBoards[i].xEnd;
            maxHeight = currentBoard.y;
        }
    }
    if(currentBoard.y == 0)
    {
        return 0;
    }
    int path1 = DetermineShortestPath(currentBoard.xStart - 1, n, currentBoard.y) + 1;
    int path2 = DetermineShortestPath(currentBoard.xEnd, n, currentBoard.y) + 1;

    int shortestPath = 0;
    if(path1<path2) shortestPath = path1;
    else shortestPath = path2;
    return shortestPath;
}
