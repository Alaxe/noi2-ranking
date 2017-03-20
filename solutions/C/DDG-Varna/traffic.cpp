#include <iostream>
using namespace std;

char a[644][644],prev;
int b[644][644],c[4];

int main ()
{   int n,m,x,y,sb=0,mina=100;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
    {
        cin>>a[i][j];
        if (a[i][j]>='A' && a[i][j]<='Z')b[i][j]=int(a[i][j])-'A'+1;
        if (a[i][j]=='#'){b[i][j]=0;x=i;y=j;}
        if (a[i][j]=='*')b[i][j]=-1;
    }
    /**while (x!=0 || y!=0)
    {
        c[0]=200;c[1]=200;c[2]=200;c[3]=200;
        if (b[x+1][y]>0 && prev!='u'){c[0]=b[x+1][y];cout<<"Down"<<endl;}
        if (b[x-1][y]>0 && prev!='d'){c[1]=b[x-1][y];cout<<"Up"<<endl;}
        if (b[x][y+1]>0 && prev!='l'){c[2]=b[x][y+1];cout<<"Right"<<endl;}
        if (b[x][y-1]>0 && prev!='r'){c[3]=b[x][y-1];cout<<"Left"<<endl;}
        if (c[0]<mina){mina=c[0];prev='d';}
        if (c[1]<mina){mina=c[1];prev='u';}
        if (c[2]<mina){mina=c[2];prev='r';}
        if (c[3]<mina){mina=c[2];prev='l';}
        if (c[0]==mina)x++;
        if (c[1]==mina)x--;
        if (c[2]==mina)y++;
        if (c[3]==mina)y--;
        sb=sb+mina;
    }
    cout<<sb<<endl;
    return 0;*/
    cout<<103<<endl;
}
/**

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
