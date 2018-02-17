#include <iostream>
using namespace std;
int main(){
    int s, t, z;
    cin>>s>>t>>z;
    unsigned long long res = 0;
    int a = 0 , b = 0;
    while(true){
        if(s>0){
            s/=2;
            a++;
        }else{
        break;}
    }    while(true){
        if(t>0){
            t/=2;
            b++;
        }else{
        break;}
    }
    a--;
    b--;

    if(a<z)
        a=z;

    for(int i = a; i < b; i++){
        unsigned long long curr = 1;
        for(int j = i; j >= i-z+1; j--){
            curr*=j;
        }
        res+=curr;
    }
        for(int j = 1; j<= z; j++){
            res/=j;
        }
    cout<<res<<endl;
    return 0;
}

