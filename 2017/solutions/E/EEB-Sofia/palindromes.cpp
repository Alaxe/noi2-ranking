#include <iostream>
using namespace std;
int main(){
int N, i, j, a=0, b=0, c=0, d=0;
cin>>N;
for(i=N-1; i>0; i--){
    for(j=N-1; j>0; j--){
        if(N/100>=1){
        a=i*j%10;
        b=i*j/10%10;
        c=i*j/100%10;
        d=i*j/1000;
        }else{
            a=i*j%10;
            b=i*j/10%10;
            c=i*j/100;
        }
        if(N/100>=1){
        if(i*j==a*1000+b*100+c*10+d*1){
            if(i<=j){
                cout<<i<<" "<<j<<endl<<i*j<<endl;
            }else{
                cout<<j<<" "<<i<<endl<<i*j<<endl;
            }
            return 0;
        }
        }else{
          if(i*j==a*100+b*10+c*1){
            if(i<=j){
                cout<<i<<" "<<j<<endl<<i*j<<endl;
            }else{
                cout<<j<<" "<<i<<endl<<i*j<<endl;
            }
            return 0;
        }
        }
    }
}
return 0;
}
