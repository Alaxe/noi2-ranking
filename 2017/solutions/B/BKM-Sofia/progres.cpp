#include <iostream>
#include <algorithm>
using namespace std;

void check (int A[],int n,int d,int N,int &c){
  for(int x=n;x<N;x++){
    if(A[n]+d==A[x]){
        c++;
        check(A,x,d,N,c);
    }
  }
}

int main () {
int c=0,N,max_d=0;
cin >> N;
int A[N];
for(int i=0;i<N;i++) {cin >> A[i];max_d=max(max_d,A[i]);}
for(int d=1;d<=max_d;d++) {
    for(int i=0;i<N;i++){
        for(int n=i+1;n<N;n++){
            if(A[i]+d==A[n]){
                c++;
                check(A,n,d,N,c);
            }
        }
    }
}
cout << c;
return 0;
}
