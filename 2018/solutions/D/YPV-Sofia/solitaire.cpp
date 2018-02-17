#include<iostream>
using namespace std;
long long numbers[101][101];
long long num(char a){
    switch(a){
        case 'A':return 1;
        case '2':return 2;
        case '3':return 3;
        case '4':return 4;
        case '5':return 5;
        case '6':return 6;
        case '7':return 7;
        case '8':return 8;
        case '9':return 9;
        case 'T':return 10;
        case 'J':return 11;
        case 'Q':return 12;
        case 'K':return 13;
    }
}
int main(){
    string table[101][101];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>table[i][j];
        }
    }
    numbers[n-1][0]=num(table[n-1][0][0]);
    for(int j=0;j<n;j++){
        for(int i=n-1;i>=0;i--){
            numbers[i][j]=max(numbers[i+1][j],numbers[i][j-1])+num(table[i][j][0]);
        }
    }
    cout<<numbers[0][n-1]<<endl;
return 0;
}
/**
4
8S AD 2C AC
TC 4H QD QS
5D 9H QC 7H
1C QC AS 2D
**/
