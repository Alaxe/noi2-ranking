#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

struct card{
string a;
int points;
char color;
};

int main() {
    int n;
    cin>>n;
    card m[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j].a;
            switch(m[i][j].a[0]){
            case 'A':m[i][j].points=1;
            case '2':m[i][j].points=2;
            case '3':m[i][j].points=3;
            case '4':m[i][j].points=4;
            case '5':m[i][j].points=5;
            case '6':m[i][j].points=6;
            case '7':m[i][j].points=7;
            case '8':m[i][j].points=8;
            case '9':m[i][j].points=9;
            case 'T':m[i][j].points=10;
            case 'J':m[i][j].points=11;
            case 'Q':m[i][j].points=12;
            case 'K':m[i][j].points=13;
            }
        }
    }



    int y=0,x=0;int sum=m[3-y][x].points;
    for(int i=0;i<n*2-2;i++){

        if(m[3-y][x].points>m[y][x+1].points||x==3){
            y++;sum+=m[y][x].points;
        }
        else if(m[3-y][x].points<=m[y][x+1].points||y==3){
             x++;sum+=m[3-y][x].points;
        }
    }cout<<sum<<endl;
		return 0;
}
