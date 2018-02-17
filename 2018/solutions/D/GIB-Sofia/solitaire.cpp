#include<iostream>
#include<cmath>
using namespace std;
int main(){
int n,result;
cin>>n;
int board[n*2][n];
int field[n][n];
char temp;
for(int y=0;y<n;y++){
    for(int x=0;x<n;x++){
        cin>>temp;
        switch(temp){
            case 'A':
                board[x][y]=1;
            break;
            case '2':
                board[x][y]=2;
            break;
            case '3':
                board[x][y]=3;
            break;
            case '4':
                board[x][y]=4;
            break;
            case '5':
                board[x][y]=5;
            break;
            case '6':
                board[x][y]=6;
            break;
            case '7':
                board[x][y]=7;
            break;
            case '8':
                board[x][y]=8;
            break;
            case '9':
                board[x][y]=9;
            break;
            case '10':
                board[x][y]=10;
            break;
            case 'J':
                board[x][y]=11;
            break;
            case 'Q':
                board[x][y]=12;
            break;
            case 'K':
                board[x][y]=13;
            break;
            default:

            break;
        }
    }
}

field[0][n-1]=0;
for(int steps=0;steps<=2*(n-2);steps++){
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(field[x][y]==steps){
                if(x<n-1){
                    field[x+1][y]=steps+1;
                }
                if(y>0){
                    field[x][y-1]=steps+1;
                }
            }
        }
    }
}

for(int steps=1;steps<=2*(n-2);steps++){
        bool go=true;
        int max=0;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(field[x][y]==steps){
                if(go){
                    max=board[x*2][y];
                    go=false;
                }else{
                    if(board[x*2][y]>max){
                        max=board[x*2][y];
                    }
                }
            }
        }
    }
    result+=max;
}

cout<<result;
return 0;
}
