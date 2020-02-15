#include <bits/stdc++.h>
using namespace std;
#include <string.h>

//Make a pair between vertex x and vertex y
void addedge(list<unsigned long long>*ls,int x,int y){
 ls[x].push_back(y);
 ls[y].push_back(x);
}

//count the number of paths exists
void path_count(list<unsigned long long>*ls,unsigned long long s,unsigned long long d,bool *visit, unsigned long long &count){
 visit[s]=true;
 if(s==d){
  count++;
 }
 else{
  list<unsigned long long>::iterator it;
  for(it=ls[s].begin();it!=ls[s].end();it++){
   if(!visit[*it]){
    path_count(ls,*it,d,visit,count);
   }
  }
 }
 visit[s]=false;
}

int main()
{
    unsigned long long x,y,answer=0;
    int n,m;
    cin>>n>>m;
 list<unsigned long long> ls[n];
 for (int i=0;i<m;i++)
 {

     cin>>x>>y;
 addedge(ls,(x-1),(y-1));
 }


 bool visit[n];

memset(visit, false, n);
 unsigned long long count=0;

    for (int i=1;i<n;i++)
    {


     for (int j=i;j<=n;j++)
     { count=0;
         path_count(ls,i,j,visit,count);
       if (count>=2) answer++;
     }
      /*for(int i=0;i<n;i++){
  visit[i]=false;
      }*/
      memset(visit, false, n);
    }


 cout<<answer<<endl;

 return 0;

}
