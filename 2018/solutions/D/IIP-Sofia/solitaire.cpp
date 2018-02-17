#include<iostream>
using namespace std;
long long N,sbor=0;
char karti[10000],boqKarti[1];

int translate(char x){
    if(x!='A' && x!='T' && x!='J' && x!='Q' && x!='K'){
        return int(x-48);
    }
    if(x=='A'){
        return 1;
    }
    if(x=='T'){
        return 10;
    }
    if(x=='J'){
        return 11;
    }
    if(x=='Q'){
        return 12;
    }
    if(x=='K'){
        return 13;
    }
}

int main(){
    cin>>N;
    long long myX=0,myY=N-1;
    long long field[N][N];
    for(long long y=0;y<N;++y){
        for(long long x=0;x<N;++x){
            cin>>karti[x+y*N]>>boqKarti[0];
            field[x][y]=translate(karti[x+y*N]);
        }
    }
    for(long long i=0;i<2*N-1;++i){
        sbor+=field[myX][myY];
        if(myX==N-1){
            myY--;
            continue;
        }
        if(myY==0){
            myX++;
            continue;
        }
        if(field[myX][myY-1]>field[myX+1][myY]){
            myY--;
        }else{
            myX++;
        }
    }
    cout<<sbor;
    return 0;
}
