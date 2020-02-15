#include<iostream>
using namespace std;
int main(){
long long n,x,nuleva=0,pyrva=1,vtora=2,c;
cin>>n>>x;
if(n==1&&x==1){
    cout<<0;
}else{
    if(n==1&&x==0){
        cout<<1;
    }else{
        if(n==1&&x==2){
            cout<<2;
        }else{
            for( ;n<=4&&n>1&&n%2==0&&n>0;n=n-2){
                if(n%2==0){
                    c=pyrva;
                    pyrva=vtora;
                    vtora=c;
                }else{
                    if(n%2==1){
                        c=nuleva;
                        nuleva=2;
                        pyrva=0;
                    }
                }
                n=n-1;
                for( ;n%2==1&&n>0;n=n-2){
                    if(n%2==1){
                        c=nuleva;
                        nuleva=pyrva;
                        pyrva=c;
                    }else{
                        if(n%2==0){
                            c=pyrva;
                            pyrva=1;
                            vtora=0;
                        }
                    }
                }
                n=n+1;
                for( ;n>4&&n>1&&n%4==0&&n>0;n=n-2){
                if(n%4==0){
                    c=pyrva;
                    pyrva=vtora;
                    vtora=c;
                }else{
                    if(n%4==3){
                        c=nuleva;
                        nuleva=2;
                        pyrva=0;
                    }
                }
                n=n-1;
                nuleva=0;
                pyrva=2;
                vtora=3;
            }
        }
        if(x==0){
    cout<<nuleva;
}else{
    if(x==1){
        cout<<pyrva;
    }else{
        if(x==2){
            cout<<vtora;
        }
    }
}
    }
    }
}

    return 0;
}
