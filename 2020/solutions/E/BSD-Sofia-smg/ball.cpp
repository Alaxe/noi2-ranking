#include<iostream>
using namespace std;
int main(){
    long long n,x,i,topcheVchasha;
    cin>>n>>x;
    topcheVchasha=x;
    for(i=n;i>0;i=i-1){
        if(i%2==1){
            if(topcheVchasha==0){
                topcheVchasha=1;
            }else{
                if(topcheVchasha==1){
                    topcheVchasha=0;
                }else{
                    if(topcheVchasha==2){}
                    }
            }
        }else{
            if(topcheVchasha==0){
            }else{
                if(topcheVchasha==1){
                    topcheVchasha=2;
                }else{
                    if(topcheVchasha==2){
                       topcheVchasha=1;
                    }
                }
            }
        }
    }
    cout<<topcheVchasha;

    return 0;
}
