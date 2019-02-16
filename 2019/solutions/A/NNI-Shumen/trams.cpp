#include <iostream>
using namespace std;
const int MAXN=10000;
int a[MAXN][MAXN], n, m;
void print()
{
    int i, j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<m; j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}

void read()
{
    int i, x, y;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        a[x][y]=1;
    }
}

int main()
{
    read();
    print();
    return 0;
}
/**
8 12
2 3
3 4
5 4
2 6
4 8
6 8
8 7
5 7
6 7
1 2
1 5
1 3
**/
