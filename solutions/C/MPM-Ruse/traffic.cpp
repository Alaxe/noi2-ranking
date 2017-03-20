#include<iostream>
using namespace std; 
long long n,m,i,j,si,sj,mini=-1,curr=0;
char tab[604][604],c;
bool used[604][604];
void solve(long long x,long long y)
{
    if(tab[x][y]!='#')curr+=tab[x][y]-'A'+1;
    used[x][y]=true;
    if(x==0 || x==n-1 || y==0 || y==m-1){if(mini>curr || mini==-1)mini=curr;return;}
    if(used[x+1][y]==false && x<n-1 && tab[x+1][y]!='*')solve(x+1,y);
    if(used[x-1][y]==false && x>0 && tab[x-1][y]!='*')solve(x-1,y);
    if(used[x][y+1]==false && y<m-1 && tab[x][y+1]!='*')solve(x,y+1);
    if(used[x][y-1]==false && y>0 && tab[x][y-1]!='*')solve(x,y-1);
    used[x][y]=false;
    curr=curr-(tab[x][y]-'A'+1);
}
int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++)
    for(j=0;j<m;j++){cin>>tab[i][j];if(tab[i][j]=='#'){si=i;sj=j;}used[i][j]=false;}
    solve(si,sj);
    cout<<mini<<endl;
    return 0;
}