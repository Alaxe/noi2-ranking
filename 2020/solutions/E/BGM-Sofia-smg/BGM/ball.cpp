#include<iostream>
using namespace std;
int main () {
long long n,x,cup1=0,cup2=1,cup3=2,topchito,i,g=0;
cin>>n>>x;
if(x==0){
        topchito=0;
    for(i=1;i<=n;i++){
        if(i%2==1){
            g=topchito;
            topchito=cup2;
            cup2=g;
        }
        if(i%2==0){
            g=cup3;
            cup3=cup2;
            cup2=g;
        }

    }

}
if(x==1){
        topchito=1;
    for(i=1;i<=n;i++){
        if(i%2==1){
            g=cup1;
            cup1=topchito;
            topchito=g;
        }
        if(i%2==0){
            g=cup3;
            cup3=topchito;
            topchito=g;
        }

    }

}
if(x==2){
        topchito=2;
    for(i=1;i<=n;i++){
        if(i%2==1){
            g=cup1;
            cup1=cup2;
            cup2=g;
        }
        if(i%2==0){
            g=topchito;
            topchito=cup2;
            cup2=g;
        }

    }

}
cout<<topchito;
return 0;
}
