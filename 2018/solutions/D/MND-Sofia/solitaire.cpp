#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
int n;
cin>>n;
char a[n*n*2];
for(int i=0;i<n*n*2;i++){
    cin>>a[i];
}
int masivNaStoinosti[n*n];
for(int i=0;i<n*n*2;i=i+2){
    if(a[i]=='A'){
        masivNaStoinosti[i/2]=1;
    }
    if(a[i]=='2'){
        masivNaStoinosti[i/2]=2;
    }
    if(a[i]=='3'){
        masivNaStoinosti[i/2]=3;
    }
    if(a[i]=='4'){
        masivNaStoinosti[i/2]=4;
    }
    if(a[i]=='5'){
        masivNaStoinosti[i/2]=5;
    }
    if(a[i]=='6'){
        masivNaStoinosti[i/2]=6;
    }
    if(a[i]=='7'){
        masivNaStoinosti[i/2]=7;
    }
    if(a[i]=='8'){
        masivNaStoinosti[i/2]=8;
    }
    if(a[i]=='9'){
        masivNaStoinosti[i/2]=9;
    }
    if(a[i]=='T'){
        masivNaStoinosti[i/2]=10;
    }
    if(a[i]=='J'){
        masivNaStoinosti[i/2]=11;
    }
    if(a[i]=='Q'){
        masivNaStoinosti[i/2]=12;
    }
    if(a[i]=='K'){
        masivNaStoinosti[i/2]=13;
    }

}
int maxRoad=0;
for(int i=0;i<n;i++){
    maxRoad=maxRoad+masivNaStoinosti[i];
}
for(int i=n;i<n*n;i=i+n){
    maxRoad=maxRoad+masivNaStoinosti[i];
}
int maxRoad2=0;
for(int i=n*(n-1);i<n*n;i++){
    maxRoad2=maxRoad2+masivNaStoinosti[i];
}
for(int i=n*n-1-n;i>=0;i=i-n){
    maxRoad2=maxRoad2+masivNaStoinosti[i];
}
int maxRoad3=0;




for(int i=0;i<n;i++){
    maxRoad3=maxRoad3+masivNaStoinosti[i];
}
for(int i=n;i<n*n;i=i+n){
    maxRoad3=maxRoad3+masivNaStoinosti[i];
}
maxRoad3=maxRoad3-masivNaStoinosti[0]+masivNaStoinosti[n+1];

int x=max(maxRoad,maxRoad2);
cout<<max(x,maxRoad3);
return 0;
}
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
