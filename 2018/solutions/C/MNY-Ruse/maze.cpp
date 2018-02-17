#include<iostream>
using namespace std;
bool way=false,bomb=false;
char l[101][101];
int a,b,c,d,mbr=15000,m,n;
void init()
{int i,j;
for(i=0;i<m;i++)
 for(j=0;j<n;j++)
  { cin>>l[i][j];
   if(l[i][j]=='B'){a=i; b=j;}
    else if(l[i][j]=='E'){c=i;b=j;}
    }
    }
void minpath()
{int i,j,br;
 for(i=0;i<m;i++)
 for(j=0;j<n;j++)
 {if(l[i][j]=='*')br++;
  else if(l[i][j]=='$')br=br+3;
  //cout<<br<<endl;
  if(br<mbr)mbr=br;
     
 }   
}    
          
 void maze(int i,int j)
 {if(i==c&&j==d){l[i][j]='*';way=true; minpath();}
 else if(l[i][j]=='#'){
        if(bomb==false){l[i][j]='$';maze(i+1,j);
          maze(i-1,j);maze(i,j+1);maze(i,j-1);
          bomb=true;}}
      else if(l[i][j]=='.'){l[i][j]='*';maze(i+1,j);
          maze(i-1,j);maze(i,j+1);maze(i,j-1);}  
     
 }
 int main()
 {int i,j;
 cin>>m>>n;
 init();
 /*for(i=0;i<m;i++)
 for(j=0;j<n;j++)
   cout<<l[i][j];*/
   //cout<<a<<b;
 maze(a,b);
if(way==false)cout<<"-1"<<endl;
 else cout<<mbr<<endl;
 return 0;    
 } 
 
 /* 6 7
    .....B.
    .#####.
    .#...#.
    .#E#.#.
    .###.#.
    .......*/
 
 