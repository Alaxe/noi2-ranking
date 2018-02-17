#include <iostream>
using namespace std;
int ans[100][100];
short grid[101][101];
short n;
int go_go(short x, short y)
{
    if(x < 0 || y >= n)
        return 0;
    if(ans[x][y] != 0)
        return ans[x][y];
    return grid[x][y] + max(go_go(x - 1, y), go_go(x, y + 1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    string curr;
    char c;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            cin >> curr;
            c = curr[0];
            switch(c)
            {
                case 'A':
                    grid[i][j] = 1;
                    break;
                case 'T':
                    grid[i][j] = 10;
                    break;
                case 'J':
                    grid[i][j] = 11;
                    break;
                case 'Q':
                    grid[i][j] = 12;
                    break;
                case 'K':
                    grid[i][j] = 13;
                    break;
                default:
                    grid[i][j] = (c - '0');
                    break;
            }
        }
    }
    cout << go_go(n - 1, 0);
    cout << endl;
    return 0;

}
