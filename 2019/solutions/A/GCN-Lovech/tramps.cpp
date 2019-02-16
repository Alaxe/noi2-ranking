/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;



void addEdge (int adj[50][50], int u, int v)
{
adj[u][v]=1;
adj[v][u]=1;
}

void dellEdge (int adj[50][50], int u, int v)
{
    adj[u][v]=0;
    adj[v][u]=0;
}




	void printGraph (int obj[50][50],int BrSp)
      {
	for (int v = 0; v < BrSp; ++v)
	  {
	    cout << "\n Adjacency list of vertex " << v << "\n head ";
	  for (int x = 0; x < BrSp; ++x)
	      if(obj[v][x]==1)cout << "-> " << x;
	    printf ("\n");
	  }
}
void calc(int a,int obj[50],int BrSp,int BrVr,int obj2[50][50],int path){
    //int maxpath=0;
    for(int i=0;i<BrSp;i++){
        dellEdge(obj2,a,i);
        cout<<"->"<<i;
        path++;
        if(obj[i]==1){
        dellEdge(obj2,a,i);
        cout<<obj2;
        cout<<"->"<<i;
        path++;calc(i,obj2[a],BrSp,BrVr,obj2,path);}
        
    }
    cout<<endl;
}
      int main ()
      { 
          int obj[50][50];
          int BrSp;
int BrVr;
           cin >> BrSp;
  cin >> BrVr;
  int a, b;
 
  for (int i = 0; i < BrVr; i++)
    {
      cin >> a;
      cin >> b;
      addEdge (obj, a, b);
    }
	for(int i=0; i<BrSp;i++){
    for(int j=0; j<BrSp;j++){
      cout<<obj[i][j]; 
      
    }cout<<endl;
}
	int path=0;
//	for (int i = 0; i < BrSp; i++)
//	  {
	   // calc ();
//	  }

for(int i=0; i<BrSp; i++){
    cout<<i;
    calc(i,obj[i],BrSp,BrVr,obj,path);
}
	cout << "Hello World";


	return 0;
      }
