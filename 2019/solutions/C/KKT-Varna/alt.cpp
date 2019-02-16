#include<bits/stdc++.h>
using namespace std;

int ms[64][64],k,m,n;

unsigned long long getgrid(int i){
  unsigned long long s=0;
  ms[1][i]=1;
  for(int i=1;i<n;++i){
    for(int j=0;j<m;++j){
      if(ms[i][j]){
        if(j-k>0)ms[i+1][j-k]+=ms[i][j];
        if(j+k<m)ms[i+1][j+k]+=ms[i][j];
        }
      }
    }
  for(int i=1;i<m;++i)s+=ms[n][i];
  return s;
  }

int main(){

unsigned long long s=0;
int sz=64*64*4;

cin>>k>>m>>n;

for(int i=1;i<m;++i){
  s+=getgrid(i);
  memset(ms,0,sz);
  }

cout<<s<<endl;

return 0;
}
