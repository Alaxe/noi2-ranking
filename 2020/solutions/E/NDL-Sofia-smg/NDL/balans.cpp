#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char collor[n];
    cin>>collor;
    int ab=0,cd=0;
    for(int i=0; i<n; i++){
        if(collor[i]=='a' || collor[i]=='b'){
            ab++;
        }else{
            cd++;
        }

    }
    for(n=n; ab!=cd; n--){
        if(collor[n-1]=='a' || collor[n-1]=='b'){
            ab--;
        }else{
            cd--;
        }
    }
    cout<<n;
    return 0;
}
