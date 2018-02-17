#include<iostream>
#include<algorithm>
using namespace std;
int matr[271][271];
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        matr[i][0] = 1;
    }
    for(int i=0; i<m; i++){
        matr[0][i] = 1;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(i-j>=0){
                matr[i][j] = matr[i][j-1] + matr[i-1][j] - matr[i-1][j-1];
                if(matr[i][j-1]%2==0 || i==j){
                    matr[i][j]++;
                }

            } else {
                matr[i][j] = matr[i][i];
            }
        }
    }

    if(m%2!=0){
        cout<<matr[n-1][m-1];
    } else {
        cout<<matr[n-1][m-1];
    }
    cout<<"\n";
    return 0;
}
