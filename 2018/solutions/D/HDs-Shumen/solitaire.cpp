#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    string v[n][n];
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            cin>>v[i][j];
        }
    }
    int ci=n-1;
    int cj=0;
    int v2[n][n];
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            if (v[i][j][0]=='A') v2[i][j]=1;
            if (v[i][j][0]=='T') v2[i][j]=10;
            if (v[i][j][0]=='J') v2[i][j]=11;
            if (v[i][j][0]=='Q') v2[i][j]=12;
            if (v[i][j][0]=='K') v2[i][j]=13;
            if (v[i][j][0]=='2') v2[i][j]=2;
            if (v[i][j][0]=='3') v2[i][j]=3;
            if (v[i][j][0]=='4') v2[i][j]=4;
            if (v[i][j][0]=='5') v2[i][j]=5;
            if (v[i][j][0]=='6') v2[i][j]=6;
            if (v[i][j][0]=='7') v2[i][j]=7;
            if (v[i][j][0]=='8') v2[i][j]=8;
            if (v[i][j][0]=='9') v2[i][j]=9;
        }
    }
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            cout<<v2[i][j]<<" ";
        }
        cout<<endl;
    }
    int m=0;
    int points=v2[ci][cj];
    for (int i=ci ; i!=ci ; i+=0) {
            for (int j=cj ; j!=cj ; j+=0) {
            if (i+1==0 && j==n-1) {points+=v2[i+1][j]; cout<<points<<endl; return 0;}
            if (i==0 && j+1==n-1) {points+=v2[i][j+1]; cout<<points<<endl; return 0;}
            if (i-1==0 && j==n-1) {points+=v2[i-1][j]; cout<<points<<endl; return 0;}
            if (i==0 && j-1==n-1) {points+=v2[i][j-1]; cout<<points<<endl; return 0;}
            if (m<v2[i+1][j] && i<n && j<n && i>=0 && j>=0) {cj=j; ci=i+1; m=v2[ci][cj];}
            if (m<v2[i][j+1] && i<n && j<n && i>=0 && j>=0) {cj=j+1; ci=i; m=v2[ci][cj];}
            if (m<v2[i-1][j] && i<n && j<n && i>=0 && j>=0) {cj=j; ci=i-1; m=v2[ci][cj];}
            if (m<v2[i][j-1] && i<n && j<n && i>=0 && j>=0) {cj=j-1; ci=i; m=v2[ci][cj];}

    }points+=v2[ci][cj];
    }cout<<points<<endl;
        return 0;
}
