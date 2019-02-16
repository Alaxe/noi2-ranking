#include<iostream>
using namespace std;
long long n,tupo,x,y=1,i,i3=1,i2,red=1,dokolko=1,redica[1000002],proba[1000002];
int main(){
cin>>n;
redica[0]=1;
for(i=1;i<n+1;i++){
    for(i2=0;i2<(i+i-1);i2++ && i3++){
        if(red<=i){
            proba[i2]=red;
            red++;
        }else{
            red--;
            for(x=0;x<i-1;x++ && i2++ && i3++){
                red--;
                proba[i2]=red;
                cout<<proba[i2];
                redica[i3]=proba[i2];
            }
            break;
        }
        cout<<proba[i2];
        redica[i3]=proba[i2];
    }

}
cout<<"\n\n";
for(i=0;i<1000002;i++){
    if(redica[i]==n){
        cout<<i+1;
        return 0;
    }
}
}
