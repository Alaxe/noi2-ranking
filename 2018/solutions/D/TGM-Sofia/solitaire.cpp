#include<iostream>
using namespace std;
int M[101][101],M1[101][101],n;

int main(){
    long long i,j;
    cin >> n;
    char N[n][n*2];
    for(i=0;i<n;i++){
        for(j=0;j<(n*2);j++){
            cin >> N[i][j];
            if(j%2==0){
                if(N[i][j]!='T' or N[i][j]!='J' or N[i][j]!='Q' or N[i][j]!='K' or N[i][j]!='A'){
                    M[i][j/2]=N[i][j]-48;
                }
                if(N[i][j]=='T'){
                    M[i][j/2]=10;
                }
                if(N[i][j]=='J'){
                    M[i][j/2]=11;
                }
                if(N[i][j]=='Q'){
                    M[i][j/2]=12;
                }
                if(N[i][j]=='K'){
                    M[i][j/2]=13;
                }
                if(N[i][j]=='A'){
                    M[i][j/2]=1;
                }
            }
        }
    }
    M1[n-1][0]=M[n-1][0];
    for(i=n-2;i>=0;i--){
        M1[i][0]=M1[i+1][0]+M[i][0];
    }
    for(i=1;i<n;i++){
        M1[n-1][i]=M1[n-1][i-1]+M[n-1][i];
    }
    for(i=1;i<n;i++){
        for(j=n-2;j>=0;j--){
            if(M1[j][i-1]>M1[j+1][i]){
                M1[j][i]=M1[j][i-1]+M[j][i];
            }else{
                M1[j][i]=M1[j+1][i]+M[j][i];
            }
        }
    }
    cout << M1[0][n-1] << endl;
return 0;
}
