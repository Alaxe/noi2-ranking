#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<math.h>

using namespace std;

int a[100][100],maxx = 0,br = 0;

int recursion(int i,int j,int n,int hod,int brhod)
{
    if(i == 0&&j == n - 1)
    {
        if((hod > maxx||br == 0)&&brhod == n * 2 - 2)
        {
            maxx = hod;
            br++;
        }
        return 0;
    }
    if(i - 1 >= 0)
    {
        recursion(i - 1,j,n,hod + a[i][j],brhod + 1);
    }
    if(j + 1 < n)
    {
        recursion(i,j + 1,n,hod + a[i][j],brhod + 1);
    }
}

int main()
{
    int n;
    cin>>n;
    string a2;
    
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cin>>a2;
            if(a2[0] >= '2'&&a2[0] <= '9')
            {
                a[i][j] = a2[0] - '0';
            }
            else if(a2[0] == 'A')
            {
                a[i][j] = 1;
            }
            else if(a2[0] == 'T')
            {
                a[i][j] = 10;
            }
            else if(a2[0] == 'J')
            {
                a[i][j] = 11;
            }
            else if(a2[0] == 'Q')
            {
                a[i][j] = 12;
            }
            else if(a2[0] == 'K')
            {
                a[i][j] = 13;
            }
        }
    }
    recursion(n - 1,0,n,0,0);
    cout<<maxx + a[0][n - 1]<<endl;
    return 0;
}