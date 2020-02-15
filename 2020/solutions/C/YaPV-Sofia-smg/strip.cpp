#include<iostream>
using namespace std;
long long pascal[52][52];
void calculate_Pacsal(){
    pascal[0][0]=1;
    pascal[1][0]=1;
    pascal[1][1]=1;
    for(int i=2;i<=50;i++){
        pascal[i][0]=1;
        for(int j=1;j<=50;j++){
            pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
        }
    }
}
int main(){
    int N,K;
    cin>>N>>K;
    calculate_Pacsal();
    cout<<pascal[N-1][K-1]<<endl;
return 0;
}
