#include<iostream>
#include<cstring>
using namespace std;
char c[100][100];
int n,m,x1,x2;
unsigned long long br=0,minbr=1000000000;
void backtracking(int x,int y,int l)
{if(x<0 || x>=n || y<0 || y>=m) {return;}
if(c[x][y]=='#'){
if(l==0) {l=1; br+=3; c[x][y]='.'; 
backtracking(x+(-1),y+0,l);//up
backtracking(x+0,y+1,l);//right
backtracking(x+1,y+0,l);//down
backtracking(x+0,y+(-1),l);//left
br-=3; c[x][y]='#';}
else return;}
if(c[x][y]=='E') {if(minbr>br) minbr=br;  return;}
if(c[x][y]=='.') {
br+=1; c[x][y]='#';
backtracking(x+(-1),y+0,l);//up
backtracking(x+0,y+1,l);//right
backtracking(x+1,y+0,l);//down
backtracking(x+0,y+(-1),l);//left
br-=1; c[x][y]='.';}
if(c[x][y]=='B') {
br+=1; c[x][y]='#';
backtracking(x+0,y+1,l);//right
backtracking(x+(-1),y+0,l);//up
backtracking(x+1,y+0,l);//down
backtracking(x+0,y+(-1),l);//left
br-=1; c[x][y]='B';}}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {for(int j=0;j<m;j++)
    {cin>>c[i][j];
    if(c[i][j]=='B'){x1=i; x2=j;}}}
    backtracking(x1,x2,0);
    if(minbr==1000000000) cout<<"-1"<<endl;
    else cout<<minbr<<endl;
    system("pause");
    return 0;
}
