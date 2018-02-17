#include <iostream>

using namespace std;

int main()
{
    int i,n,j,z,br,brmax=0;
    int y1,y2,y3,x1,x2,x3;
    cin>>n;
    int a[n][n];
    for(i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[0][i];
    }
    for(i=1;i<=n-1;i++)
    {

for(j=1;j<=n-2-i;j++)
    {br=0;

for(z=1;z<=n-3-j;z++)
    {
        x1=a[i][0];
        x2=a[j][0];
        x3=a[z][0];
        y1=a[0][i];
        y2=a[0][j];
        y3=a[0][z];
if((x3-x1)*(y2-y1)==(y3-y1)*(x2-x1))br++;

if(br>brmax)brmax=br;

    }
    if(br>brmax)brmax=br;
    }
    if(br>brmax)brmax=br;
    }
cout<<brmax+2;
    return 0;
}
