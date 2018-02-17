#include<iostream>
using namespace std;
int main() {

int x, y;
cin>>x>>y;

int pole[x][y];

int n;

cin>>n;
n++;
int squares[n][4];
squares[n-1][0]=0;
squares[n-1][1]=0;
squares[n-1][2]=x;
squares[n-1][3]=y;

    for(int i=0;i<y;i++) {
        for(int i2=0;i2<x;i2++) {
            pole[i2][i]=n;
        }
    }


for(int i=0;i<n-1;i++) {
    cin>>squares[i][0]>>squares[i][1]>>squares[i][2]>>squares[i][3];
    squares[i][2]=squares[i][0]+squares[i][2];
    squares[i][3]=squares[i][1]+squares[i][3];

    int x1=squares[i][0], y1=squares[i][1], x2=squares[i][2], y2=squares[i][3];

    for(int i2=y1;i2<=y2-1;i2++) {
        for(int i3=x1;i3<=x2-1;i3++) {
            pole[i3][i2]=i;
        }
    }
}

int t;
cin>>t;

int point[t][3], result[t];


for(int i=0;i<t;i++) {
    cin>>point[i][0]>>point[i][1];
    result[i]=0;
    int pointX=point[i][0];
    int pointY=point[i][1];
    int vnas=pole[pointX][pointY];
    int x1=squares[vnas][0], y1=squares[vnas][1], x2=squares[vnas][2], y2=squares[vnas][3];
if(vnas!=n) {
    for(int i2=y1;i2<y2;i2++) {
        for(int i3=x1;i3<x2;i3++) {
            if(pole[i3][i2]==vnas) {
                result[i]++;
            }
        }
    }
} else {
    for(int i4=0;i4<y;i4++) {
        for(int i5=0;i5<x;i5++) {
            if(pole[i5][i4]==n)
                result[i]++;
        }
    }
}
}

for(int i=0;i<t;i++){
    cout<<result[i]<<endl;
}

return 0;
}
