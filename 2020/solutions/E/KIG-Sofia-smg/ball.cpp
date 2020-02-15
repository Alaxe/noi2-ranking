#include<iostream>
using namespace std;
int main(){
    long long n,chasha1=0,chasha=1,kopie;
    short ball;
    cin>>n>>ball;
    for(long long i=n;i>0;i--){
        if(i%2==0){
            if(ball==2){
                ball--;
            }else if(ball==1){
                ball++;
            }
        }else{
            if(ball==1){
                ball--;
            }else if(ball==0){
                ball++;
            }
        }
    }
    cout<<ball;
    return 0;
}
