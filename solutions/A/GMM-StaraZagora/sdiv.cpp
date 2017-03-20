#include<iostream>
using namespace std;
int A[1000000], Result, B, n, g = 0, m, br = 0;
bool Used[1000000];
void Check(int Res){
    if(Res%n==0)br++;
}
void Combinate(int i){
    Check(Result);
    for(int j = 0;j<g;j++){
        if(Used[j]==false){
            Used[j]= true;
            Result *= 10;
            Result += A[j];
            Combinate(i+1);
            Result /= 10;
            Used[j] = false;
        }
    }
}
int main(){
    int H;
    cin>>B;
    cin>>n>>m;
    H = B;
    H/=10;//zashtoto g - index pochva ot 0
    while(H!=0){
        g++;
        H/=10;
    }
    for(int i = g;i>=0;i--){
        A[i] = B%10;
        B/=10;
    }
    for(int i = 0;i<g;i++){
        Result = A[i];
        Combinate(i);
        Used[i] = true;
    }
    cout<<br%m;
    return 0;
}