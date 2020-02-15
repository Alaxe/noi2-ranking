#include <iostream>
using namespace std;
int main(){
    int chasha[3],Nakraq,brHoda;
    for(int i=0;i<3;i++){
        chasha[i]=0;
    }
    cin>>brHoda>>Nakraq;
    chasha[Nakraq]=1;
    while(brHoda>0){
        if(brHoda%2==0){
            swap(chasha[1],chasha[2]);
        }else{
            swap(chasha[1],chasha[0]);
        }
        brHoda--;
    }
    if(chasha[0]==1){
        cout<<0;
    }else{
        if(chasha[1]==1){
            cout<<1;
        }else{
            cout<<2;
        }
    }
    return 0;
}
