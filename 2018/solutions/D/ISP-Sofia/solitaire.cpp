#include<iostream>

using namespace std;

const int MAX_N=103;
int matrix[MAX_N][MAX_N];

int convert(char a){
    switch(a){
        case 'A': return 1;
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        default : return a-'0';
    }
}

int main(){

    cin.tie();
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        char a[2];
        for(int j=0; j<n; j++){
            cin >> a[0] >> a[1];
            matrix[n-i][j+1]=convert(a[0]);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            matrix[i][j]+=max(matrix[i-1][j], matrix[i][j-1]);
        }
    }

    cout << matrix[n][n] << '\n';

    return 0;
}

/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
