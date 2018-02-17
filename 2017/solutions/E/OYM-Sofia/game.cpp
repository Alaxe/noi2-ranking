#include<iostream>
using namespace std;
int main(){
long long a,b,c[200],razlika=99999999999999999999999,index=0,sbor=0;
cin>>a>>b;
for(int i=0;i<200;i++){
    cin>>c[i];
    if(c[i]%2==0){
        sbor+=c[i];
    }
    if(c[i]>a){
        if(c[i]-a<=razlika){
            razlika=c[i]-a;
            index=i+1;
        }
    }else{
        if(a-c[i]<=razlika){
            razlika=a-c[i];
            index=i+1;
        }
    }
    if(sbor>b){
        break;
    }
}
if(sbor>0){
    cout<<index<<" "<<sbor;
}
return 0;
}


