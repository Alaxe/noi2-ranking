#include<bits/stdc++.h>
using namespace std;
int brmax=0;
int m;
int n[100][100];
void ant(int i, int j,int br)
{
    if(i<0 or j<0 or i>m-1 or j>m-1)return;
    br+=n[i][j];
   // cout<<br<<endl;
    if(i==0 and j==m-1)
    {
        if(br>brmax)brmax=br;
        return;
    }
    ant(i-1,j,br),ant(i,j+1,br);
}

int main(){
    ios_base::sync_with_stdio(0);

cin>>m;
string p;
for(int i=0;i<m;i++)
{
   for(int j=0;j<m;j++)
   {
       cin>>p;
       if(p[0]=='A')n[i][j]=1;
       if(p[0]=='2')n[i][j]=2;
       if(p[0]=='3')n[i][j]=3;
       if(p[0]=='4')n[i][j]=4;
       if(p[0]=='5')n[i][j]=5;
       if(p[0]=='6')n[i][j]=6;
       if(p[0]=='7')n[i][j]=7;
       if(p[0]=='8')n[i][j]=8;
       if(p[0]=='9')n[i][j]=9;
       if(p[0]=='T')n[i][j]=10;
       if(p[0]=='J')n[i][j]=11;
       if(p[0]=='Q')n[i][j]=12;
       if(p[0]=='K')n[i][j]=13;
   }

}
ant(m-1,0,0);
cout<<brmax<<endl;

return 0;
}
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
/*
3
AC TS 2H
5D KD QS
1C 9D 7D
*/
