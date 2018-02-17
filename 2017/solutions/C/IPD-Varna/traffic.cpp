#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct poz
{
    int i, j;
};
int n, m, mas[660][660];
poz start;
char a;
int main ()
{
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            cin.get(a);
            if (a=='#')
            {
                mas[i][j]=0;
                start.i=i;
                start.j=j;
            }
            if (a=='*') mas[i][j]=-1;
            else  mas[i][j]=a-'A'+1;

        }
        cin.get(a); /// '\n'
    }
    return 0;
}
/*
8 12
NY****AZ****
*SH*D**CHMW*
*CJ**G**LZO*
*JMS****NGG*
*JKPKN#YORC*
************
KJWWGDPLQMXL
TGLAKBQCRQSD
*/
