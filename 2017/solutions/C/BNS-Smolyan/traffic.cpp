#include<iostream>
using namespace std;
char arr[700][700];
int map[700][700];
int leave(int,int);
int n,m;
int getTime(char);
int main()
{
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == '#')
            {
                x = i;
                y = j;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            map[i][j] = getTime(arr[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << leave(x,y);
    return 0;
}
int getTime(char a)
{
    if(a == '#')
    {
        return 0;
    }
    if(a == '*')
    {
        return -1;
    }
    return (int)(a-64);
}
int leave(int x, int y)
{
    if(x == 0 || y == 0 || y == m-1 || x == n-1 && map[x][y] != -1) return map[x][y];
    if(map[x][y] == -1) return 0;
    return map[x][y] + leave(x+1,y) + leave(x,y+1) + leave(x-1,y) + leave(x,y-1) + leave(x+1,y+1) + leave(x-1,y-1) + leave(x+1,y-1) + leave(x-1,y+1);
}
