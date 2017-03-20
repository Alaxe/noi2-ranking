#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <limits.h>
#include <cmath>
#include <queue>
#include <string.h>
#include <cstring>
using namespace std;
int maxN;
struct sq{
     int x,y;
     int h,w,S, ans=0;
     vector<sq*> V;
     void add(sq * a){V.push_back(a);}
     void debug(){
          cout << x << " " << y << endl;
          cout << w << " " << h << endl << endl;
     }
     sq(){
          cin >> x >> y >> w >> h;
          S = w*h;
     }
     sq(int a, int b, int c, int d){
          x = a,y = b, w = c, h = d;
          S = w*h;
     }
     bool in(sq & B){
          if(B.x > this->x && B.y > this->y && B.x+B.w < this->x+this->w && B.y+B.h < this->y+this->h)
               return true;
          else return false;
     }
     bool in(int x, int y){
          if(x > this->x && y > this->y && x < this->x+this->w && y < this->y+this->h)
               return true;
          else return false;
     }
     bool getNext(int x, int y, sq* curr){
          for(int i = 0; i < V.size(); i++){
               if(V[i]->in(x,y)){
                    curr = V[i];
                    return true;
               }
          }
          return false;
     }
     int getS(){
          if(ans)return ans;
          ans = S;
          for(int i = 0; i < V.size(); i++) ans-=V[i]->S;
          return ans;
     }
};
bool help(sq A, sq B){
     if(A.h == B.h)return A.w < B.w;
     return A.h < B.h;
}

vector<sq> A;

class uniFind{
public:
     uniFind(){
          for(int i = 0; i < 11000; i++){
               index[i]=i;
               Size[i]=1;
          }
     }
     int root(int i){
          while(i!=index[i]){
               index[i]=index[index[i]];
               i = index[i];
          }
          return i;
     }
     bool areConn(int a, int b){
          return root(a) == root(b);
     }
     void unite(int a, int b){
          a = root(a);
          b = root(b);
          if(a == b)return;
          if(Size[a]>Size[b]){
               Size[a]+=Size[b];
               index[b] = a;
          }else{
               Size[b]+=Size[a];
               index[a] = b;
          }
     }
private:
     int Size[11000];
     int index[11000];
};

int main(){
     uniFind U;
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     int N, M, Q;
     cin >> N >> M;
     cin >> Q;
     for(int i = 0; i < Q; i++){
          A.push_back(sq());
     }
     A.push_back(sq(0,0,N,M));
     sort(A.begin(),A.end(),help);
     for(int i = 0; i < A.size(); i++){
          for(int j = i-1; j >=0; j--){
               if(!U.areConn(i,j)){
                    if(A[i].in(A[j])){
                         //cout << j << " is inside " << i << endl;
                         //A[j].debug();
                         //A[i].debug();
                         U.unite(i,j);
                         A[i].add(&A[j]);
                    }
               }//else{
                    //cout << i << " and " << j << " are already connected!" << endl;
                    //A[j].debug();
                    //A[i].debug();
               //}
          }
     }
     int T;
     cin >> T;
     for(int i = 0; i < T; i++){
          int x, y;
          cin >> x >> y;
          sq *curr;
          for(int i = 0; i < A.size(); i++){
               if(A[i].in(x,y)){
                    curr = &A[i];
                    //cout << "found one : ";
                    //A[i].debug();
                    break;
               }
          }
          while(curr->getNext(x,y,curr)){
               //cout << "Going deeper" << endl;
          }
          //cout << "ANSWER IS: " << curr->getS() << endl;
          cout << curr->getS() << endl;
     }
}
/*
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3

*/
