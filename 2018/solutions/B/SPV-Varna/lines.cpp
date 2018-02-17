#include<bits/stdc++.h>
#include<math.h>
#define endl '\n'
using namespace std;

struct Coord{
    int x, y;
    Coord(){}
    Coord(int _x, int _y){
        x = _x;
        y = _y;
    }
};

struct constants{
    float a, b;
    constants(){}
    constants(float _x, float _y){
        a = _x;
        b = _y;
    }
};

Coord arr[1000];
constants ab[1000][1000];

int main(){

int n;
cin>>n;

for(int i=0; i<n; i++){
    cin>>arr[i].x>>arr[i].y;
}

for(int i=0; i<n; i++){
    Coord c = arr[i];
    for(int j=i+1; j<n; j++){
        Coord c1 = arr[j];
        float a;
        if(c.x-c1.x!=0) a = float(c.y-c1.y)/(c.x-c1.x);
        else a = 0;
        a = float(c.y-c1.y)/(c.x-c1.x);
        float b = (c.y-c1.y) - a*(c.x-c1.x);
        ab[i][j].a=a;
        ab[i][j].b=b;
    }
}
int maxcoa = 0;
int maxcob = 0;
for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
        int coa = 0;
        int cob = 0;
       for(int ii=0; ii<n; ii++){
            for(int jj=ii; jj<n; jj++){

                if(ab[i][j].a==ab[ii][jj].a) coa++;
                if(ab[i][j].b==ab[ii][jj].b) cob++;
            }
        }
        if(maxcoa<coa) maxcoa=coa;
        if(maxcob<cob) maxcob=cob;
    }
}
maxcoa--;
maxcob--;
int co = min(maxcoa, maxcob);

int result = (1+int(sqrt(1+4*(co*2))))/2;
cout<<result<<endl;

}
/*
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3

6
0 2
2 3
-2 1
-2 -2
6 5
-2 3

*/
