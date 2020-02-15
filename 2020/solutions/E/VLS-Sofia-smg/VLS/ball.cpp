#include<iostream>
using namespace std;
long long x, n;
int nechetno(int x){
    if(x == 1){
        return 0;
    }else if(x == 0){
        return 1;
    }else {
        return 2;
    }
}
int chetno(int x){
    if(x == 1){
        return 2;
    }else if(x == 2){
        return 1;
    }else {
        return 0;
    }
}
int main(){
    cin>>n>>x;
    for(int i = n; i > 0; i --){
        if(i%2 == 0){
            x = chetno(x);
        }else{
            x = nechetno(x);
        }
    }
    cout<<x<<endl;
    return 0;
}
