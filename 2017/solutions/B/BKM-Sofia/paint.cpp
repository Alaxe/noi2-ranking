#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Rect{
int X,Y,W,H,S;
};

struct Point{
int X,Y;
};

bool is_rect_in_rect (Rect R1,Rect R2){
if ((R2.X>R1.X and (R2.X+R2.W)<(R1.X+R1.W)) and (R2.Y>R1.Y and (R2.Y+R2.H)<(R1.Y+R1.H))) return true;
else return false;
}

bool is_point_in_rect(Point P,Rect R) {
if ((P.X>=R.X and P.X<=(R.X+R.W)) and (P.Y>=R.Y and P.Y<=(R.Y+R.H))) return true;
else return false;
}

void ch_area(Rect &R1,Rect R2){
if(is_rect_in_rect(R1,R2))R1.S-=R2.S;
}

double dist (Rect R1,Point R2){
return sqrt(pow(R1.X-R2.X,2)+pow(R1.Y-R2.Y,2));
}

int main () {
int A,B,S0;
cin >> A >> B;
S0=A*B;
int N;
cin >> N;
Rect R[N];
for(int i=0;i<N;i++) {cin >> R[i].X >> R[i].Y >> R[i].W >> R[i].H;R[i].S=R[i].H*R[i].W;}
int T;
cin >> T;
Point P[T];
int min_d[T],ind[T];
for(int i=0;i<T;i++)min_d[i]=11000;
for(int i=0;i<T;i++) cin >> P[i].X >> P[i].Y;
for(int i=0;i<N;i++) {
    for(int n=0;n<N;n++){
        if(i!=n){
            ch_area(R[i],R[n]);
        }
    }
}
for(int i=0;i<N;i++) S0-=R[i].S;
for(int i=0;i<T;i++){
    int c=0;
    for(int n=0;n<N;n++){
        if(is_point_in_rect(P[i],R[n])){c++;ind[i]=n;}
    }
    if(c==0)cout<<S0<<endl;
    else if(c==1)cout<<R[ind[i]].S<<endl;
    else{
        for(int x=0;x<N;x++){
                if(min_d[i]>dist(R[x],P[i])){min_d[i]=dist(R[x],P[i]);ind[i]=x;}
            }
        cout<<R[ind[i]].S<<endl;
        }
    }
    return 0;
}
