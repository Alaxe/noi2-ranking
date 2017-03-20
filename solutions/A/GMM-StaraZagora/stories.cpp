#include<iostream>
using namespace std;
int main(){
    
    
    long int N, K, First, Mul, Add, Mod, Sum = 0, Bestof3 = 0;
    long int A[200000];//ne tragvashe pri men s po golqm broi elementi ....
    cin>>N>>K;
    
    while(K>N||K<1||N>200000){
        if(K>N)cout<<"K ne moje da e po golqmo ot N.";
        if(K<1||N>200000)cout<<"K i N trqbva da sa ot 1 do 200 000.";
        cin>>K>>N;
    }
    
    cin>>First>>Mul>>Add>>Mod;
    A[0] = First;
    Sum += A[0];
    for(int i = 1;i<N;i++){
        A[i] = ((A[i-1]*Mul)+Add)%Mod;
        Bestof3 = A[i];
        for(int j = i;j!=i-K;j--){
            if(j==0){
                if(A[0]>A[i])Bestof3 = A[0];
                break;
            }
            
            if(A[j]>Bestof3)Bestof3 = A[j];
        }
        
        Sum += Bestof3;
        
    }
    
    cout<<Sum;
    
    return 0;
}